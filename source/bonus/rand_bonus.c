int pseudo_random(int seed)
{
	seed = (seed * 1103515245 + 12345) & 0x7fffffff;
	return (seed);
}
