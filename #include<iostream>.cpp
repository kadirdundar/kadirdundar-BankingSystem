#include<iostream>
using namespace std;

//class tanımlıyoruz
class BankingSystem
{
		private:
			long int account_number,mob_number,balance,newbalance,amount;
			string name,address,email;
			char choice,ch;
		public:
			void open_new_account(int n,BankingSystem *ob);
			void account_info();
			void withdraw();
			void deposit();
			void balance_info();
			int check(long int account_number,BankingSystem *ob,int n); 
			int  ret();
};

//fonksiyonların
void BankingSystem::open_new_account(int n,BankingSystem *ob)
{
		newbalance=0,balance=0;
		int f=0;
		cout<<"merhaba sen bizim "<<(n+1)<<" müşterimizsin"<<endl<<endl;
		cout<<"istenilen hesap numarasını girin"<<endl;
		do{
			cin>>account_number;
			if(account_number==check(account_number,ob,n))
			{
				cout<<"bu hesap numarası zaten var farklı bir numara girin"<<endl;
				f=1;
			}
			else
				f=0;
		}while(f==1);
		getline(cin,name);
		cout<<"isminiz"<<endl;
		getline(cin,name);
		cout<<"adresiniz"<<endl;
		getline(cin,address);
		cout<<"telefon numaranız"<<endl;
		cin>>mob_number;
		getline(cin,address);
		cout<<"e-posta adresiniz"<<endl;
		getline(cin,email);
		cout<<"para yatırmak istiyormusunuz E/H"<<endl;
			cin>>choice;
		do{
			if(toupper(choice)=='E')
			{
				cout<<"miktarı giriniz"<<endl;
				cin>>newbalance;
				balance=balance+newbalance;
			}
			else if(toupper(choice)=='H')
			{
				cout<<"öenmli değil sıfır bakiyeli hesabınız da olabilir"<<endl;
				break;
			}
			else
				cout<<"geçerli bir komut giriniz"<<endl;
			cout<<"para yatırmak istiyormusunuz E/H"<<endl;
			cin>>ch;
		}while(toupper(ch)=='E');
		cout<<endl;
		cout<<"merhaba "<<name<<" hesap numaranız "<<account_number<<" bakiyeniz->"<<balance<<endl<<endl;
}

//hesabı kontrol ediyoruz

int BankingSystem::check(long int x,BankingSystem *ob,int n)
{
	for(int i=0;i<n;i++)
	{
		if(ob[i].ret()==x)
			return x;
	}
	return 0;
	
}


//BELİRLİ BİR KAYDIN HESAP NUMARASINI ALMA İŞLEVİ

int  BankingSystem::ret()
{
	return account_number;
}


//hesap bilgilerini kontrol eden fonksiyon
void BankingSystem::account_info()
{
		cout<<"merhaba "<<name<<" hesap numaranız "<<account_number<<" bakiyeniz->"<<balance<<endl;
}


//miktarı alma fonksiyonu

void BankingSystem::withdraw()
{
			cout<<"merhaba "<<name<<" bakiyeniz-> "<<balance<<endl<<" çekilecek miktarı giriniz"<<endl;
			do{	
				cin>>amount;
				if(balance<amount)
					cout<<"yetersiz bakiye"<<endl;
				else
					balance-=amount;
				cout<<"çekime devam etmek istermisiniz -E/H"<<endl;
				cin>>ch;	
			}while(toupper(ch)=='E');
		cout<<"yeni bakiyeniz "<<balance<<endl;
}


//yatırma fonksiyonu
void BankingSystem::deposit()
{
			cout<<"merhaba "<<name<<" bakiyeniz-> "<<balance<<endl<<" yatırılacak miktarı giriniz"<<endl;
			do{
				cin>>amount;
				balance+=amount;
				cout<<"yatırma işlemine devam etmek istermisniz? -Y/N"<<endl;
				cin>>ch;	
			}while(toupper(ch)=='E');
	cout<<"yeni bakiyeniz "<<balance<<endl;
}


//bakiye bilgisini kontrol etme

void BankingSystem::balance_info()
{
			cout<<"merhaba "<<name<<" bakiyeniz-> "<<balance<<endl;
}

//ana fonksiyon

int main(void)
{
		int wish,i=0,n=0,f=0;;
		char demand;
		BankingSystem ob[100];
		long int tmp=ob[0].ret();
		do{
		    f=0;
			cout<<"\t\t\t"<<"bankaya hoş geldiniz "<<endl<<endl;
			cout<<"yeni hesap açmak için 1 e basınız"<<endl;
			cout<<"hesap bilgileriniz için 2 ye basınız"<<endl;
			cout<<"para çekmek için 3 e basınız"<<endl;
			cout<<"para yatırmak için 4 e basınız"<<endl;
			cout<<"bakiyenizi kontrol etmek için 5 e basınız"<<endl;
			cout<<"çıkmak için 6 ya basınız"<<endl<<endl;
			cin>>wish;
			switch(wish)
			{
				case 1:
					ob[i].open_new_account(n,ob);
					n=n+1;
					i=i+1;
					break;
				case 2:
				do{
					cout<<"hesap numaranızı giriniz"<<endl;
					cin>>tmp;
					for(int j=0;j<=n-1;j++){
						if(tmp==ob[j].ret()){
							ob[j].account_info();
							f=1;
							break;
					    }	
					}
					if(f==0)
						cout<<"geçersiz hesap numarası"<<endl;
					cout<<"Diğer hesaplarınızı kontrol etmek istermisiniz -E/H"<<endl;
			        cin>>demand;
			        }while(toupper(demand)=='E');
						break;
				case 3:
						cout<<"hesap numaranızı giriniz"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++){
							if(tmp==ob[j].ret()){
								ob[j].withdraw();
								f=1;
								break;
							}
						}	
						if(f==0)
							cout<<"geçersiz hesap numarası"<<endl;
						break;
				case 4:
						cout<<"hesap numaranızı giriniz"<<endl;
						cin>>tmp;
						for(int j=0;j<=n-1;j++){
							if(tmp==ob[j].ret()){
								ob[j].deposit();
								f=1;
							    break;
							}
						}
						if(f==0)
						cout<<"geçersiz hesap numarası"<<endl;
						break;
				case 5:
				        do{
				    		cout<<"hesap numaranızı giriniz"<<endl;
						    cin>>tmp;
						    for(int j=0;j<=n-1;j++){
							    if(tmp==ob[j].ret()){
							    	ob[j].balance_info();
						    		f=1;
						    		break;
							    }
					    	}
				    		if(f==0)
					    		cout<<"geçersiz hesap numarası"<<endl;
							cout<<"Diğer hesaplarınızı kontrol etmek istermisiniz -E/H"<<endl;
			            cin>>demand;
			            }while(toupper(demand)=='E');
						break;
				case 6:
						cout<<"teşekkürler"<<endl;
						demand='H';
						break;
				default:
						cout<<"geçersiz seçim";
						break;
			}	
			cout<<"banka işlemlerine devam etmek istiyormusunuz -E/H"<<endl;
			cin>>demand;
		}while(toupper(demand)=='E');
}
