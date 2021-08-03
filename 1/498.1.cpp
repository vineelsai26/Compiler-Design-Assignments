#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    vector<string> keywords{"abstract", "boolean", "byte", "break", "class", "case", "catch", "char", "const", "continue", "default", "do", "double", "else", "enum", "extends", "final", "finally", "float", "for", "goto", "if", "implements", "import", "instanceof", "int", "interface", "long", "native", "new", "package", "private", "protected", "public", "return", "short", "static", "assert", "strictfp", "super", "switch", "synchronized", "this", "throw", "throws", "transient", "try", "void", "volatile", "while"};
    vector<string> separators{"(", ")", "[", "]", "{", "}", ";", ","};
    vector<string> operators{"+", "–", "/", "*", "%", "<", ">", "<=", ">=", "==", "!=", "&", "|", "^", "&&", "||", "!", "~", "=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "=>", ">>", "<<", ">>>"};

    ifstream fin("sample.java");

    bool multilineComment = false;
    bool singlelineComment = false;

    while (fin)
    {
        string line;
        vector<string> words{};
        getline(fin, line);

        size_t pos = 0;
        while ((pos = line.find(" ")) != string::npos)
        {
            if (line.substr(0, pos).find_first_not_of(' ') != std::string::npos)
            {
                words.push_back(line.substr(0, pos));
            }

            line.erase(0, pos + 1);
        }

        words.push_back(line);

        string comment = "";

        for (int i = 0; i < words.size(); i++)
        {
            // cout << words[i] << endl;
            // if (words[i].compare("/*") == 0)
            // {
            //     multilineComment = true;
            // }
            // if (words[i].compare("*/") == 0)
            // {
            //     multilineComment = false;
            // }
            if (words[i].compare("//") == 0)
            {
                singlelineComment = true;
            }
            if (singlelineComment == true || multilineComment == true)
            {
                comment += words[i] + " ";
            }
            if (singlelineComment == false && multilineComment == false)
            {
                for (int j = 0; j < keywords.size(); j++)
                {
                    if (words[i].compare(keywords[j]) == 0)
                    {
                        bool displayIdentifier = true;
                        cout << "Keyword: " << words[i] << endl;
                        for (int j = 0; j < keywords.size(); j++)
                        {
                            if (words[i + 1].compare(keywords[j]) == 0)
                            {
                                displayIdentifier = false;
                            }
                        }
                        if (displayIdentifier == true)
                        {
                            cout << "Identifier: " << words[i + 1] << endl;
                        }
                    }
                }

                for (auto &ch : words[i])
                {
                    if (ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';' || ch == ',')
                    {
                        cout << "Seperator: " << ch << endl;
                        continue;
                    }
                }

                for (int j = 0; j < operators.size(); j++)
                {
                    if (words[i].compare(operators[j]) == 0)
                    {
                        cout << "Operator: " << words[i] << endl;
                    }
                }

                if (isdigit(words[i][0]))
                {
                    cout << "Number: " << words[i][0] << endl;
                }
            }
        }
        if (singlelineComment == true)
        {
            cout << "Single Line Comment: " << comment << endl;
            comment = "";
            singlelineComment = false;
        }
        // if (multilineComment == true)
        // {
        //     cout << "Multi Line Comment: " << comment << endl;
        // }
    }

    fin.close();
    return 0;
}