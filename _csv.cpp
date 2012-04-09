#include <iostream>
#include <string>

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
/*

int main() {
	ifstream ifs("C:\\data.csv");	// �f�[�^�t�@�C�����J���B
	CistreamCsv istreamcsv(ifs);
	int aiTable[3][3];
	{for (int iRow = 0; iRow < 3; ++iRow) {
		{for (int iCol = 0; iCol < 3; ++iCol) {
			istreamcsv >> aiTable[iRow][iCol];	// �v�f����ǂݍ��ށB�R���}�͎������������B
			cout << aiTable[iRow][iCol] << ",";	// �f�o�O�p
		}}
		istreamcsv >> endl;						// ���̍s�Ɉڂ�Bendl �ŉ��s�����������B
		cout << endl;							// �f�o�O�p
	}}
    return 0;
}
*/