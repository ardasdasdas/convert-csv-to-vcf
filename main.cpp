#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;
vector<string> saveMemberToVector(string str);
void writeToVcfFile(ofstream& vcfFile, vector<string> member);
string year;
string community = "BBTK"; // Bilgisayar ve Bilisim Teknolojileri Kulubu
/*
	@author		: Muzaffer Arda Uslu | usluarda58@gmail.com
	@date		: 10/22/2020
	@brief		: This code is convert .csv file to .vcf file.

	Excel save order:

	+--------+------------+-------------+------------+------------------+--------------------+
	|  NAME	 |   SURNAME  | STUDENT ID  | DEPARTMENT |   PHONE NUMBER   |       E-MAIL       | 
	|--------|------------|-------------|------------|------------------|--------------------|
	|  ARDA	 |    USLU    | 22222222222 | Bil. Müh.  |  22222222222     |usluarda58@gmail.com| 1
	|	 |            |             |            |                  |			 | 2	
	+--------+------------+-------------+------------+------------------+--------------------+ .

	CSV file format:
	-> ARDA,USLU,22222222222,Bil. Müh.,22222222222,usluarda58@gmail.com

	VCF file output:
	BEGIN:VCARD
	VERSION:3.0N;CHARSET=utf-8:USLU BBTK2020;ARDA;;;;
	FN;CHARSET=utf-8:ARDA USLU BBTK2020
	ORG:BBTK
	TEL;TYPE=WORK,MOBILE:022222222222
	EMAIL:usluarda58@gmail.com
	END:VCARD

	------------------------------------------------------------------------------------------

	Name format is ARDA USLU BBTK{year}
*/
int main() {
	string csvFileName, vcfFileName;
	cout << "Enter csv file name with extension (XXXXXXX.csv) : ";
	cin >> csvFileName;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter vcf file name with extension (YYYYYYY.vcf) : ";
	cin >> vcfFileName;

	// control files extensions
	if (csvFileName.find(".csv") == string::npos || vcfFileName.find(".vcf") == string::npos) {
		cout << "Error... Please enter valid extension.";
		return -1;
	}

	ifstream csvFile;
	csvFile.open(csvFileName);

	ofstream vcfFile;
	vcfFile.open(vcfFileName);

	// control files.
	if (csvFile.fail())  {
		cout << csvFileName << " can not open!" << endl;
		return -2;
	}
	else if (vcfFile.fail()) {
		cout << vcfFileName << " can not open!" << endl;
		return -3;
	}
	
	while (!csvFile.eof())
	{
		string memberLine;
		getline(csvFile, memberLine);
		vector<string> member = saveMemberToVector(memberLine);
		writeToVcfFile(vcfFile, member);
	}

	csvFile.close();
	vcfFile.close();

	return 0;
}

vector<string> saveMemberToVector(string memberLine) {
	vector<string> member;
	stringstream lineStream(memberLine);
	string col;

	// split the line by comma
	while (getline(lineStream, col, ',')) {
		member.push_back(col);
	}
	if (!lineStream && col.empty())
	{
		member.push_back("");
	}
	return member;
}

void writeToVcfFile(ofstream& vcfFile, vector<string> member) {
	string firstName = member.at(0);
	string secondName = member.at(1) + " " + community + year;// see Name Format in 38. row
	string phoneNumber = member.at(4);
	string email = member.at(5);
	string organization = "BBTK";
	// if someone enters their phone number without a leading zero
	if (phoneNumber[0] != '0' && phoneNumber[0] != '+') {
		phoneNumber = "0" + phoneNumber;
	}
	vcfFile << "BEGIN:VCARD" << endl << "VERSION:3.0N;CHARSET=utf-8:" << secondName << ";" << firstName
		<< ";;;;" << endl << "FN;CHARSET=utf-8:" << firstName << " " << secondName << endl << "ORG:" << organization << endl
		<< "TEL;TYPE=WORK,MOBILE:" << phoneNumber << endl << "EMAIL:" << email << endl << "END:VCARD" << endl;
}
