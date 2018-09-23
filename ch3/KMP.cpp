#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int * GetNext(string s);
int SubString(string t, string p,int m);
int main()
{
	string t = "abcdgdfabcd";
	string p = "abcd";
	int * next = GetNext(p);
	
	int n = SubString(t, p,2);
	cout << endl;
	cout << n << endl;
	
	
	return 0;
}

int * GetNext(string s)
{
	int length = s.length();
	int * next = new int[length];
	next[0] = -1;
	int j = 0;
	int k = -1;
	while (j < length-1)
	{
		if (k == -1 || s[k] == s[j])
		{
			j++;
			k++;
			next[j] = k;
		}
		else
		{
			k = next[k];
		}
	}

	return next;
}

int SubString(string t, string p,int m)
{
	int * next = GetNext(p);
	int length_t = t.length();
	int length_p = p.length();
	int i = m;
	int j = 0;
	while (i < length_t  && j < length_p)
	{
		if (j == -1 || t[i] == p[j])
		{
			i++;
			j++;
		}
		else
		{
			j = next[j];
		}
	}
	if (j == length_p)
		return i - j;
	else
		return -1;
}