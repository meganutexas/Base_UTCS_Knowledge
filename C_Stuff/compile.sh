#! /bin/sh

WHITE="\033[0m"
PURPLE="\033[35m"
CYAN="\033[96m"
RED="\033[31m"
YELLOW="\033[33m"
GREEN="\033[32m"

echo ""
echo -e -n "${WHITE}Enter .c file to compile:${CYAN} "
read FILE
OUTPUT=$(echo $FILE | cut -f1 -d\.)

echo -e -n "${WHITE}Enter compilation flags:${CYAN} "
read FLAGS

echo -e -n "${WHITE}Show warnings? (y/n):${CYAN} "
read WARNINGS

echo -e "${WHITE}"

echo -e "${PURPLE}Compiling...${WHITE}"

gcc ${FLAGS} ${FILE} -o ${OUTPUT} > compile.txt 2>&1

MISSING=$(grep -c "No such file or directory" compile.txt)
if [ $MISSING -ne 0 ]; then
	echo ""
	echo "-------------------------------"
	echo -e "${RED}ERROR:${WHITE} File ${CYAN}${FILE}${WHITE} does not exist!"
	echo "-------------------------------"
	rm compile.txt
	return
fi

UNRECOGNIZED=$(grep -c "unrecognized command line option" compile.txt)
if [ $UNRECOGNIZED -ne 0 ]; then
	BAD_FLAG=$(grep "unrecognized command line option" compile.txt | cut -f7 -d' ')
	echo ""
	echo "----------------------------------------"
	echo -e "${RED}ERROR:${WHITE} Flag ${CYAN}${BAD_FLAG}${WHITE} is unrecognized by gcc!"
	echo "----------------------------------------"
	rm compile.txt
	return
fi

if ! [ -z $WARNINGS ]; then
	if [ $WARNINGS == "y" ]; then
		echo ""
		echo "-----------------------"
		echo -e "${YELLOW}WARNINGS:${WHITE}"
		echo "-----------------------"
		grep "warning" compile.txt
		echo "-----------------------"
	fi
fi

ERRORS=$(grep -c "error" compile.txt)
if [ $ERRORS -ne 0 ]; then
	echo ""
	echo "------------------------"
	echo -e "${RED}ERRORS:${WHITE}"
	echo "------------------------"
	grep "error" compile.txt
	
	echo ""
	echo -e "${PURPLE}Note:${WHITE} Binary file ${CYAN}${OUTPUT}${WHITE} was not updated"
	rm compile.txt
	return
else
	echo ""
	echo -e "${GREEN}Compilation Successful!${WHITE}"
	echo -e "${PURPLE}Note:${WHITE} Binary file saved as ${CYAN}${OUTPUT}${WHITE}"
	echo ""
fi


rm compile.txt
