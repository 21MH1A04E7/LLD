#include <bits/stdc++.h>
using namespace std;

class DocumentEditor
{
private:
    vector<string> doucumentElements;
    string renderedDocument;
public:
    //Adds tex as a plain string
    void addText(string text){
        doucumentElements.push_back(text);
    }
    //Adds an image represented by its file path
    void addImage(string imagePath){
        doucumentElements.push_back(imagePath);
    }
    //Renders the document by checking the type of each element at runtime
    string rederDocument(){
        if(renderedDocument.empty()){
            string result;
            for(auto element:doucumentElements){
                if(element.length()>4 && (element.substr(element.length()-4)==".jpg" ||
                element.substr(element.length()-4)==".png")){
                    result+="[Image : "+element+" ]"+"\n";
                }else{  
                    result+=element+"\n";
                }
            }
            renderedDocument=result;
        }   
        return renderedDocument;
    }

    void saveToFile(){
        ofstream file("document.txt");
        if(file.is_open()){
            file<<rederDocument();
            file.close();
            cout<<"Document saved to document.txt"<<endl;
        }else{
            cout<<"Error: Unable to open file for writing."<<endl;
        }
    }
};
int main()
{
    DocumentEditor *editor=new DocumentEditor();
    editor->addText("Hello , world");
    editor->addImage("picture.jpg");
    editor->addText("this is document editor");
    editor->addImage("hariom.jpg");
    editor->addText("super man");
    cout<<editor->rederDocument()<<endl;
    editor->saveToFile();
}