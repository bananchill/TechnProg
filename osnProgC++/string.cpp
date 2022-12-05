#include <iostream>
#include <cctype>
#include <string>
#include <fstream>


char *merge_charStrings(char *cdestination, const char *csource, const char *csource2, int const size);

std::string merge_Strings( std::string &cdestination, const std::string &source, const std::string &source2);

int main() {
    int SIZE = 0;
    std::ifstream in;
    in.open(("C:\\Users\\maksm\\Desktop\\untitled1\\data.txt"));
    if (!in.is_open()) {
        std::cerr << "File can not be opened\n";
        return 1;
    }

    int string1_length = 0;
    int string2_length = 0;
    while (!in.eof()) {
        in >> SIZE;
//        std::cout << SIZE << std::endl;
        if (SIZE == 0) {
            break;
        }
        char *phrase = new char[SIZE + 1];
        char *phrase2 = new char[SIZE + 1];
        //       in.seekg(1, std::ios::cur);
        in.ignore();
        in.getline(phrase, SIZE + 1, '\n');
        in.getline(phrase2, SIZE + 1, '\n');
        std::cout << phrase << std::endl << std::endl ;
        std::cout << phrase2 << std::endl << std::endl ;
        char *cdestination = new char[(SIZE + 3)*2];
        std::string stringPhrase = phrase;
        std::string stringPhrase2 = phrase2;
        std::string dest = stringPhrase;
        std::cout << merge_charStrings(cdestination, phrase, phrase2, SIZE + 1) << std::endl<< std::endl;
        std::cout << merge_Strings(dest,stringPhrase, stringPhrase2) << std::endl<< std::endl;
        delete[] phrase;
        delete[] phrase2;
        delete[] cdestination;
        SIZE = 0;
    }
    in.close();

    return 0;
}

char *merge_charStrings(char *cdestination, const char *csource, const char *csource2, int const size) {
    int i = 0, j = 0, k = 0;
    int count = 0;
    while(csource[i]){
        cdestination[i] = csource[i];
        i++;
        count++;
    }
    i = 0;
    while (csource[i]) {
        while (csource2[j]) {
            if (csource[i] == csource2[j]) {
                cdestination[count + k] = csource2[j];
                k++;
            }
            j++;
        }
        i++;
        j = 0;
    }
    cdestination[size + count ] = '\0';
    return cdestination;
}

std::string merge_Strings( std::string &cdestination, const std::string &source, const std::string &source2) {
    for (char j: source2) {
        if(source.find(j)!= std::string::npos)
            cdestination.push_back(j);
    }
    return cdestination;
}