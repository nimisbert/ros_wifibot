#include "sharp.h"

int main(int argc, char **argv)
{
	sharp S;
	S.set_sharp_addr("0x0b");
	S.sharp_launch(argc, argv);
}
