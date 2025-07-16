// AI was used to assist me a lot here

#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

/* DB just reads the line number you give it.

Example:
Hello World! (index 0)
Other value (index 1)
 */

class db
{
public:
    // Have to use different names because c++ is like this
    db(const string& XdbFilepath) {
        // Do nothing
        dbFilePath = XdbFilepath;
    }
    void setupDB()
    {
        string line;
        ifstream dbRead(dbFilePath);
        if (dbRead.is_open())
        {
            cout << "Opening file..." << std::endl;
            while (getline(dbRead, line))
            {
                contents.push_back(line);
            }
            length = contents.size();
            cout << "Success" << std::endl;
        }
        else
        {
            cout << "Unable to open file... Creating db.txt" << std::endl;
            ofstream dbWrite(dbFilePath);
            dbWrite << "";
            contents = vector<string>(0);
            length = 0;
        }
    }
    void setIndex(int index, string value)
    {
        string currLine;
        int lineCounter;
        // Handle out of bounds
        if (index >= length) {
            contents.resize(index + 1);
            length = index;
        }

        contents[index] = value;
    }
    string readIndex(int index)
    {
        // cout << contents[index];
        return contents[index];
    }

    void removeIndex(int index) {
        contents.erase(contents.begin() + index);
        length -= 1;
    }

    void clear() {
        contents.clear();
        if (!contents.empty()) {
            cout << "Vector not emptied...";
        }
        length = 0;
    }

    void writeToFile() {
        ofstream dbWrite(dbFilePath);
        if (dbWrite.is_open())
        {
            for (const auto &element : contents)
            {
                dbWrite << element << "\n";
            }
        }
        else
        {
            // Handle the error
            std::cerr << "Unable to write contents to db.";
        }
    }

    int getSize() {
        return length;
    }

    // Destructor - makes it more confusing for programmer
    // ~db()
    // {
    //     ofstream dbWrite(dbFilePath);
    //     if (dbWrite.is_open())
    //     {
    //         for (const auto &element : contents)
    //         {
    //             dbWrite << element << "\n";
    //         }
    //         cout << "Saved changes! Exiting program.";
    //     }
    //     else
    //     {
    //         // Handle the error
    //         std::cerr << "Unable to write contents to db.";
    //     }
    //     // Save changes to file
    //     dbRead.close();
    //     dbWrite.close();
    // }

private:
    // Casting integer type?
    int length{0};
    vector<string> contents;
    ifstream dbRead;
    ofstream dbWrite;
    string dbFilePath;
};

// Remember to setup a timer lol
// For me it took 2.43 seconds (pretty fast lol)
// db& apparently "passes a reference" so it's just a way of doing it without copying the variable
void test(db& database) {
    for (int i = 0; i < 10000; i++) {
        database.setIndex(i, to_string(i));
    }
    cout << database.readIndex(5000) << '\n';
    cout << database.readIndex(9999) << '\n';
}

// Experimental encryption function. Didn't work :(
void encrypt() {
    string content = "Test";
    string encrypted = "";
    int secret = 5000;
    int secret2 = 5001;
    for (int i = 0; i < content.length(); i++) {
        int asciiVersion = int(content[i]);
        string convertedBack = to_string(secret * (asciiVersion) / secret2);
        if (convertedBack.length() >= 2) {
            // cout << convertedBack << '\n';
            int firstTwo = stoi(convertedBack.substr(0, 2));
            cout << firstTwo << " -< " << '\n';
            cout << 'a' + (firstTwo % 26) << " <- " << '\n';
        } else {
            cout << "Numbers too small!";
        }
    }
}

int main()
{
    db database("db.txt");
    database.setupDB();
    // database.getContents();
    database.setIndex(10000, "Test");
    database.writeToFile();
    database.clear();
    return 0;
}
