#include <gmpxx.h>
#include <math.h>
#include <iostream>

using namespace std;

int main () {
	mpf_set_default_prec(100000);
	mpf_class k=1,s=2,total,twoP=2,nF=6;
	mp_exp_t exponent;
	int n=19001,b=10;
	for(int i=0;i<n;i++)
	{
		s=s+k;
		s=sqrt(s);
		k=s;
		s=2;
	}
	s=s-k;
	s=sqrt(s);
	//cout << s << endl;
	mpf_pow_ui(twoP.get_mpf_t(),twoP.get_mpf_t(),19000);
	nF=nF*twoP;
	total=nF*s;
	char* mes=(char *)malloc(sizeof(char)*200000);
	mpf_get_str(mes,&exponent,b,0,total.get_mpf_t());
	string pi(mes);
	//cout << total << endl;
	//cout << pi << endl;
	int t,l,r;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> l >> r;
		string values=pi.substr(l,r-l+1);
		cout << values << endl;
	}
	return 0;
}
