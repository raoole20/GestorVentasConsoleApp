
struct Identify
{
	int _id;
	Identify() { static int id = 1; _id = id++; }
};