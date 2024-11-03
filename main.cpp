#include <iostream>
#include <string>
#include "Dict.hpp"

using namespace std;

int main() {
    Dict<string,int> phone_directory;
    phone_directory.add("Tom", 4236);
    phone_directory.add("Pat", 4237);
    cout << "Tom " << "Ext.: " << phone_directory["Tom"] << endl;
    cout << "Pat " << "Ext.: " << phone_directory["Pat"] << endl;
    Dict<int,string> id_numbers;
    id_numbers.add(102304, "Tom");
    id_numbers.add(102305, "Pat");
    cout << id_numbers[102304] << endl;
    cout << id_numbers[102305] << endl;
    return 0;
}
