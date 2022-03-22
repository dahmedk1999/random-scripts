//Return 1 if current architecture uses Little Endian
//Return 0 if Big Endian
int whatEndian(void)
{
uint32_t num= 0x01;
unsigned char* n = (unsigned char*)&num;
// n[0]= 01 | n[1]= 00 | n[2]= 00 | n[3]= 00 | Little
// n[0]= 00 | n[1]= 00 | n[2]= 00 | n[3]= 01 | Big
return n[0];
}