#include <bits/stdc++.h>

using namespace std;

// Abstraction for document elements
class DocumentsElement
{
public:
    virtual string render() = 0;
};

// Concrete implementation for text elements
class TextElement : public DocumentsElement
{
private:
    string text;

public:
    TextElement(string text)
    {
        this->text = text;
    }
    string render()
    {
        return text;
    }
};

// Concrete implementation for image elements
class ImageElement : public DocumentsElement
{
private:
    string imagePath;

public:
    ImageElement(string imagePath)
    {
        this->imagePath = imagePath;
    }
    string render()
    {
        return "[Image: " + imagePath + "]";
    }
};

// NewLineElement represents a line break in the documnet.
class NewLineElement : public DocumentsElement
{
public:
    string render()
    {
        return "\n";
    }
};

// TapSpaceElement represents a tab space in the documnet.
class TapSpaceElement : public DocumentsElement
{
public:
    string render()
    {
        return "\t";
    }
};

class Document
{
private:
    vector<DocumentsElement *> documentsElements;

public:
    void addElement(DocumentsElement *element)
    {
        documentsElements.push_back(element);
    }
    string render()
    {
        string result;
        for (auto element : documentsElements)
        {
            result += element->render();
        }
        return result;
    }
};

class Persistence
{
public:
    virtual void save(string data) = 0;
};

class FileStorage : public Persistence
{
public:
    void save(string data)
    {
        ofstream outFile("document_good.txt");
        if (outFile)
        {
            outFile << data;
            outFile.close();
            cout << "Document saved to document_good.txt" << endl;
        }
        else
        {
            cout << "Error: unable to save the doucument" << endl;
        }
    }
};

class DBStorage : public Persistence
{
public:
    void save(string data)
    {
        cout << "Saved in to database" << endl;
    }
};

class DocumentEditor{
private:
    Document * document;
    Persistence* storage;
    string renderedDocument;
public:
    DocumentEditor(Document* document,Persistence* storage){
        this->document=document;
        this->storage=storage;
    }
    void addText(string text){
        document->addElement(new TextElement(text));
    }
    void addImage(string imagePath){
        document->addElement(new ImageElement(imagePath));
    }
    void addNewLine(){
        document->addElement(new NewLineElement());
    }
    void addTapSpace(){
        document->addElement(new TapSpaceElement());
    }
    string renderDocument(){
        if(renderedDocument.empty()){
            renderedDocument=document->render();
        }
        return renderedDocument;
    }
    void save(){
        storage->save(renderDocument());
    }
};



int main()
{
    Document* document=new Document();
    Persistence* persistence=new FileStorage();

    DocumentEditor* editor=new DocumentEditor(document,persistence);

    //Simulate a Client using the editor with common text formatting features.
    editor->addText("Hello, world");
    editor->addNewLine();
    editor->addImage("picture.jpg");
    editor->addTapSpace();
    editor->addText("Indented text after a tab space");
    editor->addNewLine();
    editor->addImage("picture2.png");
    cout<<editor->renderDocument()<<endl;
    editor->save();

}