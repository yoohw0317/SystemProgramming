// code written by Seohu Yoo, Kangwon National University

int bitAnd(int x, int y) {
  return ~(~x|~y);
}

int anyEvenBit(int x) {
	int answer = x |(x >> 16);
	answer = answer | (answer >> 8);
	answer = answer | (answer >> 4);
	answer = answer | (answer >> 2);
  return answer&0x01;
}

int allOddBits(int x) {
	int answer = x & (x >> 16);
	answer = answer & (answer >> 8);
	answer = answer & (answer >> 4);
	answer = answer & (answer >> 2);
	answer = answer >> 1;
  return answer&0x01;
}

int logicalShift(int x, int n) {
	int neg = ~(1 << 31);
	int maskZero =(neg << (!n)|0x01);
	int mask =((maskZero>> n) << 1| 0x01);;
  return (x >> n) & mask;
}

int logicalNeg(int x) {
	int answer = x | (x >> 16);
	answer = answer | (answer >> 8);
	answer = answer | (answer >> 4);
	answer = answer | (answer >> 2);
	answer = answer | (answer >> 1);
       	return ~answer& 0x01;
}

int bitCount(int x) {
 int answer = 0;
 int filter = 0x55 + (0x55 << 8);
 int filter2 = 0x33 + (0x33 << 8);
 int filter3 = 0x0f + (0x0f << 8);
 int filter4 = 0xff + (0xff << 16);
 int filter5 = 0xff + (0xff << 8);
 filter = filter + (filter << 16);
 filter2 = filter2 + (filter2 << 16);
 filter3 = filter3 + (filter3 << 16);
 answer = x& filter;
 answer = answer + ((x>>1) & filter);
 answer = (answer & filter2) + ((answer>>2) & filter2);
 answer = (answer & filter3) + ((answer>>4) & filter3);
 answer = (answer & filter4) + ((answer>>8) & filter4);
 answer = (answer & filter5) + ((answer>>16) &filter5);
 return answer;
}

int tmin(void) {
  return (1<<31);
}

int isPositive(int x) {
	int msb =( (x >> 31) & 0x01);
	return! (msb | !x);
}

int sign(int x) {
	int checkZero = (!x ^ 0x01) & 0x01;
	int signbit = (x >> 31);
       	return checkZero | signbit;
}

int addOK(int x, int y) {
	int msb1 = (x >> 31) & 0x01;
	int msb2 = (y >> 31) & 0x01;
	int msbs =((x + y) >> 31) &0x01;
       	return (msb1 ^ msb2)|!((msb1|msb2) ^ msbs);
}

int isLess(int x, int y) {
	int yTcomp = ~y + 1;
	int sum = x + yTcomp;
	return ((x & (x^y)) |((~(x^y))&(sum))) >> 31 & 0x01; 

}
unsigned floatAbsVal(unsigned uf) {
	int exp = (uf >> 23) & 0xff;
	int frac = uf &	0x7fffff;
	if (exp == 0xff && frac != 0)
		return uf;
	else
		return uf & 0x7fffffff;
}

unsigned floatNegate(unsigned uf) {
	int msb = uf >> 31;
	int exp = (uf >> 23) & 0xff;
	int frac = uf & 0x7fffff;
	if (exp == 0xff && frac != 0)
		return uf;
	if (msb == 0)
		return (uf + 0x80000000);
	else
		return uf & 0x7fffffff;
}

int floatFloat2Int(unsigned uf) {
	int msb = (uf >> 31);
	int exp = (uf >> 23) & 0xff;
	int frac = (uf & 0x7fffff) + 0x800000;
	int E = exp - 127;
	if (exp == 0xff|| E > 31)
		return 0x80000000;
	if (E < 0 || exp == 0)
		return 0;
	if (E-23 >= 0)
		frac = frac << (E-23);
	else 
		frac = frac >> (23-E);
	if (msb == 0)
		return frac;
	else
		return (~frac)+ 1;

}
