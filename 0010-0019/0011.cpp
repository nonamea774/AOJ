#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <set>
#include <cmath>

namespace CSV{
	class CistreamCsv { // http://homepage2.nifty.com/well/Stream.html CSV Stream
		// �}�j�s�����[�^ endl �̒�`
		friend CistreamCsv& CSV::endl(CistreamCsv& riscsv);
	private:
		std::istream& m_ris;     // ���͂Ɏg�� istream �̎Q��
	public:
		CistreamCsv(std::istream& ris) : m_ris(ris) {}
		CistreamCsv& operator >>(int& ri) {
			ri = 0;
			int iChar = 0;
			// �󔒂�ǂݔ�΂��B
			while (isspace(iChar = m_ris.get()) && iChar != '\n') {}
			if (iChar == EOF ) { return *this; }
			std::string strValue;
			if (iChar == '\n') { m_ris.putback(iChar); iChar = 0; }
			else               { strValue += iChar;               }
			// �R���}�܂œǂށB
			while ((iChar = m_ris.get()) != ',' && iChar != EOF && iChar != '\n') {
				strValue += iChar;
			}
			ri = std::atoi(strValue.c_str());
			if (iChar == EOF ) { return *this;         }
			if (iChar == '\n') { m_ris.putback(iChar); }
			return *this;
		}
		// �}�j�s�����[�^���󂯓���邽�߂̑}�����Z�q
		CistreamCsv& operator >>(CistreamCsv& (*pmanipulatorfunction)(CistreamCsv&)) {
			return (*pmanipulatorfunction)(*this);
		}
	};
	CistreamCsv& endl(CistreamCsv& riscsv) {
        int iChar = 0;
        while ((iChar = riscsv.m_ris.get()) != '\n' && iChar != EOF) {}        // �s���܂œǂݔ�΂��B
        return riscsv;
    }
};
int main(int,char**){
	int w,n;
	std::cin >> w >> n;
	CSV::CistreamCsv CSVin(std::cin);
	CSVin>> CSV::endl;

	std::vector<int> dl;
	dl.reserve(w);
	for(int i(0);i<w;++i) dl.push_back(i);
	while(n--){
		int s1,s2;
		CSVin>> s1>>s2>>CSV::endl;
		//std::cout << s1<<s2<<std::endl;
		std::swap(dl[s1-1],dl[s2-1]);
	}
	for(int i(0);i<w;++i) std::cout << dl[i]+1<<std::endl;
	return 0;
}
