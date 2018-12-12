#!/bin/bash

# Alex Swindle
# CS352 Fall 18
# Assignment 11: testCode shell script
# Purpose: a bash grading script that takes a program name and directory of testcases then runs the tests against an example executable


# Get the 2 arguments from the command line
PROGPATH=$1
TESTDIR=$2
CURDIR=$(pwd)

### CHECK THE PROGRAM NAME ###

# If no program was specified, read from stdin and make sure it succeeded
if [ -z $PROGPATH ]; then
	read PROGPATH
	if [ ! $? -eq 0 ]; then
		echo "ERROR: Couldn't read filename from stdin"
		exit 1
	fi
fi
# Check that the program is executable
if [[ ! -x $PROGPATH ]]; then
	echo "ERROR: $PROG not executable"
	exit 1
fi
# Strip off any other path information from program name, create executable program name
PROG=${PROGPATH##*/}
EXPROG=ex_${PROG}

### CHECK THE TEST DIRECTORY ###

# If no test directory was specified, read from stdin and make sure it succeeded
if [ -z $TESTDIR ]; then
	read TESTDIR
	if [ ! $? -eq 0 ]; then
		echo "ERROR: Couldn't read testcase directory from stdin"
		exit 1
	fi
fi
# Check that the directory is valid
if [ ! -d $TESTDIR ]; then
	echo "ERROR: invalid directory"
	exit 1
fi

# Move into the test directory
pushd $TESTDIR >/dev/null

# Check that the example executable is, in fact, executable
if [[ ! -x $EXPROG ]]; then
	echo "ERROR: $EXPROG not executable"
	exit 1
fi

# Grab all of the testcases
TESTCASES=$(ls -1 test_${PROG}*)

### PROCESS EACH TEST CASE ###
for Test in $TESTCASES; do

	### TIMEOUT SECTION ###
	
	# Run timeout, store the return code
	{
	timeout 2s ${CURDIR}/${PROG} <${Test} >myOut 2>myErr
	} &>/dev/null
	TIMEOUT=$?
	
	# Abnormal: > 128
	if [ $TIMEOUT -ge 128 ]; then
		echo "*** testcase: ${Test} [ FAILED – Abnormal termination ]"
	
	# Timed out: 124
	elif [ $TIMEOUT -eq 124 ]; then
		echo "*** testcase: ${Test} [ FAILED – Timed out ]"
	
	# Success: Anything else. Then check for the various pieces
	else
		### TIMEOUT SUCCEEDED SECTION ###
		
		# Run ex_prog, store return code
		$EXPROG <${Test} >exOut 2>exErr
		EXRETURN=$?
		
		# Check stdout first
		diff myOut exOut >/dev/null
		DIFFRESULT=$?
		if [ $DIFFRESULT -eq 0 ]; then
			echo "*** testcase: ${Test} [ stdout - PASSED ]"
		else
			echo "*** testcase: ${Test} [ stdout - FAILED ]"
		fi
		
		# Check Return Code
		if [ $TIMEOUT -eq $EXRETURN ]; then
			echo "*** testcase: ${Test} [ return code - PASSED ]"
		else
			echo "*** testcase: ${Test} [ return code - FAILED ]"
		fi
		
		# Check stderr
		if [ -s myErr ]; then
			if [ -s exErr ]; then
				echo "*** testcase: ${Test} [ stderr - PASSED ]"
			else
				echo "*** testcase: ${Test} [ stderr - FAILED ]"
			fi
		else
			if [ -s exErr ]; then
				echo "*** testcase: ${Test} [ stderr - FAILED ]"
			else
				echo "*** testcase: ${Test} [ stderr - PASSED ]"
			fi
		fi
		
		### VALGRIND SECTION ###
		
		# Run valgrind, save its output and return code
		valgrind --error-exitcode=123 ${CURDIR}/${PROG} <$Test &>valgrindOut
		VALGRINDRETURN=$?
		if [ $VALGRINDRETURN -eq 123 ]; then
			echo "*** testcase: ${Test} [ valgrind - FAILED ]"
		else
			echo "*** testcase: ${Test} [ valgrind - PASSED ]"
		fi
		
		# Check memory freed
		grep "ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)" <valgrindOut >memOut
		if [ -s memOut ]; then
			echo "*** testcase: ${Test} [ memory free - PASSED ]"
		else
			echo "*** testcase: ${Test} [ memory free - FAILED ]"
		fi
	fi

done
popd >/dev/null