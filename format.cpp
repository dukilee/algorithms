#include <bits/stdc++.h>

using namespace std;

void addTemplate(){
	ifstream templateFile;
	templateFile.open("template.cpp");
	string s;
	bool endReached = false;
	vector<string> v;
	while(getline(templateFile, s)){
		if(s.find("FINISH")!=string::npos){
			endReached = true;
			break;
		}
		v.push_back(s);
	}
	if(!endReached){
		cout<<"[ERROR] There's no end to template file\n";
		cout<<"Please add '//FINISH' to template file\n";
	}
	for(int i = 0; i<v.size(); i++){
		cout<<v[i]<<endl;
	}
	templateFile.close();
}

void addAlgorithm(){
	bool started = false;
	string s;
	while(getline(cin, s)){
		if(s.find("START") != string::npos) started = true;
		if(started) cout<<s<<endl;
	}

	if(!started) cout<<"[ERROR] Algorithm file never starts\n";
	if(!started) cout<<"Please add '//START' to algorithm file\n";
}

int main(){
	addTemplate();
	addAlgorithm();
}
