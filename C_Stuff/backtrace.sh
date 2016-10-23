#! /bin/sh

WHITE="\033[0m"
PURPLE="\033[35m"
LIGHT_BLUE="\033[94m"
CYAN="\033[96m"
RED="\033[31m"
YELLOW="\033[33m"
GREEN="\033[32m"

echo -e "${WHITE}"
if [ "$#" -eq 0 ]; then
	echo "------------------------------------------"
	echo -e "${RED}ERROR:${WHITE} Must have at least one argument!"
	echo -e "   ${CYAN}usage:${WHITE} source backtrace.sh [call stack]"
	echo "------------------------------------------"
	echo ""
	return
fi

echo -e -n "Enter the name of the binary to do backtrace on:${CYAN} "
read BINARY
objdump -d -l $BINARY > dump.txt 2> error.txt

echo -e "${WHITE}"
ERROR=$(grep -c "No such file" error.txt)
if [ $ERROR -ne 0 ]; then
	echo "---------------------------------------"
	echo -e "${RED}ERROR:${WHITE} Binary '${CYAN}${BINARY}${WHITE}' does not exist!"
	echo "---------------------------------------"
	echo ""
	rm dump.txt
	rm error.txt
	return
fi

for i in $@
do
	LINE=$(grep -n "$i" dump.txt | cut -f1 -d:)
	TEST=$(head -n $LINE dump.txt 2>&1 | grep -c invalid)
	if [ $TEST -ne 0 ]; then
		echo "----------------------------------------------------------------------------"
		echo -e "${RED}ERROR:${WHITE} All arguments must be hexadecimal numbers of addresses in the binary!"
		echo -e "   ${YELLOW}Invalid argument: ${CYAN}${i}${WHITE}"
		echo "----------------------------------------------------------------------------"
		echo ""
		rm dump.txt
		rm error.txt
		return
	fi
done

echo "--------------------------------------------------------------------------------"
echo -e "${GREEN}BACKTRACE:${WHITE} in order from newest to oldest function calls"
echo -e "   ${YELLOW}Note:${WHITE} if file name and line number are ${PURPLE}UNKNOWN${WHITE} recompile program with -g flag"
echo "--------------------------------------------------------------------------------"
echo  ""

for i in $@
do
	LINE=$(grep -n "$i" dump.txt | cut -f1 -d:)
	FUNCTION=$(head -n $LINE dump.txt | tac | grep -m 1 -e ">:" | cut -f2 -d\<)
	FUNCTION=$(echo $FUNCTION | cut -f1 -d\>)

	INFO=$(head -n $LINE dump.txt | tac | grep -m 1 ".c:" | rev | cut -f1 -d\/ | rev)
	FILE=$(echo $INFO | cut -f1 -d:)
	LINE=$(echo $INFO | cut -f2 -d:)
	LINE=$(echo $LINE | cut -f1 -d' ')

	if [ -z "$FILE" ]; then
		FILE="UNKNOWN"
	fi

	if [ -z "$LINE" ]; then
		LINE="UNKNOWN"
	fi

	echo -e "${CYAN}${FUNCTION}${WHITE} in ${PURPLE}${FILE}${WHITE} at line ${LIGHT_BLUE}${LINE}${WHITE}\n"
done

echo "------------------------------------------------------------------------------"

rm dump.txt
rm error.txt
