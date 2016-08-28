#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

void lower(std::string& data)
{
    std::transform(data.begin(), data.end(), data.begin(), ::tolower);
}

std::string getExtension(const std::string& filename)
{
    std::size_t extensionIndex = filename.find_last_of(".");
    return filename.substr (extensionIndex + 1, filename.size() - 1);
}

int main()
{
    std::map<std::string,std::string> mimeTable;
    int N; // Number of elements which make up the association table.
    cin >> N; cin.ignore();
    int Q; // Number Q of file names to be analyzed.
    cin >> Q; cin.ignore();
    for (int i = 0; i < N; i++) {
        string EXT; // file extension
        string MT; // MIME type.
        cin >> EXT >> MT; cin.ignore();
        lower(EXT);
        mimeTable[EXT] = MT;
    }
    for (int i = 0; i < Q; i++) {
        string FNAME; // One file name per line.
        getline(cin, FNAME);
        lower(FNAME);
        std::string extension = getExtension(FNAME);
        //std::cout << FNAME << " " << extension << " : " <<  mimeTable[extension] << std::endl;
        auto it = mimeTable.find(extension);
        if(it != mimeTable.end())
        {
            std::cout << it->second << std::endl;
        }
        else
        {
            std::cout << "UNKNOWN" << std::endl;
        }
    }
}