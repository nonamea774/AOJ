#include <iostream>
#include <string>

namespace CSV{
	class CistreamCsv { // http://homepage2.nifty.com/well/Stream.html CSV Stream
		// マニピュレータ endl の定義
		friend CistreamCsv& CSV::endl(CistreamCsv& riscsv);
	private:
		std::istream& m_ris;     // 入力に使う istream の参照
	public:
		CistreamCsv(std::istream& ris) : m_ris(ris) {}
		CistreamCsv& operator >>(int& ri) {
			ri = 0;
			int iChar = 0;
			// 空白を読み飛ばす。
			while (isspace(iChar = m_ris.get()) && iChar != '\n') {}
			if (iChar == EOF ) { return *this; }
			std::string strValue;
			if (iChar == '\n') { m_ris.putback(iChar); iChar = 0; }
			else               { strValue += iChar;               }
			// コンマまで読む。
			while ((iChar = m_ris.get()) != ',' && iChar != EOF && iChar != '\n') {
				strValue += iChar;
			}
			ri = std::atoi(strValue.c_str());
			if (iChar == EOF ) { return *this;         }
			if (iChar == '\n') { m_ris.putback(iChar); }
			return *this;
		}
		// マニピュレータを受け入れるための挿入演算子
		CistreamCsv& operator >>(CistreamCsv& (*pmanipulatorfunction)(CistreamCsv&)) {
			return (*pmanipulatorfunction)(*this);
		}
	};
	CistreamCsv& endl(CistreamCsv& riscsv) {
        int iChar = 0;
        while ((iChar = riscsv.m_ris.get()) != '\n' && iChar != EOF) {}        // 行末まで読み飛ばす。
        return riscsv;
    }
};
/*

int main() {
	ifstream ifs("C:\\data.csv");	// データファイルを開く。
	CistreamCsv istreamcsv(ifs);
	int aiTable[3][3];
	{for (int iRow = 0; iRow < 3; ++iRow) {
		{for (int iCol = 0; iCol < 3; ++iCol) {
			istreamcsv >> aiTable[iRow][iCol];	// 要素を一つ読み込む。コンマは自動処理される。
			cout << aiTable[iRow][iCol] << ",";	// デバグ用
		}}
		istreamcsv >> endl;						// 次の行に移る。endl で改行が処理される。
		cout << endl;							// デバグ用
	}}
    return 0;
}
*/