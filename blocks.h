//Modify this file to change what commands output to your statusbar, and recompile using the make command.
static const Block blocks[] = {
	/*Icon*/	/*Command*/		/*Update Interval*/	/*Update Signal*/
	{"  ", "uname -r",					0,		8},
	{" ", "free -h | awk '/^Mem/ { print $3\"/\"$2 }' | sed s/i//g",	5,		8},
	{" ", "grep 'cpu ' /proc/stat | awk '{usage=($2+$4)*100/($2+$4+$5)} END {print usage \"%\"}'",					5,		14},

	{" " , "date '+%b %d (%a) %I:%M%p'",					60,		1},
	//{"ﲊ ", "free --mebi | sed -n '2{p;q}' | awk '{printf (\"%2.2fGiB/%2.2fGiB\n\", ( $3 / 1024), ($2 / 1024))}'",     5,      14},
	{" ", "pacman -Qu | grep -Fcv \"[ignored]\"",					60*60*24,		8},
	{" ", "newsboat -x print-unread",					60*60*12,		6},
	{" ", "acpi | cut -d' ' -f4-5",					10,		3},
};

//sets delimeter between status commands. NULL character ('\-2') means no delimeter.
static char delim[] = "  ";
static unsigned int delimLen = 5;
