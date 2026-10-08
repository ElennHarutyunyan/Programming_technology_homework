#include <iostream>
#include <string>
#include <map>

class Document {
public:
    virtual Document* clone() const = 0;
    virtual void print() const = 0;
    virtual ~Document() {}
};

class PdfDocument : public Document {
private:
    std::string content;

public:
    PdfDocument(std::string c) : content(c) {}

    Document* clone() const override {
        return new PdfDocument(*this); // Copy constructor
    }

    void print() const override {
        std::cout << "PDF Document Content: " << content << std::endl;
    }
};

class WordDocument : public Document {
private:
    std::string content;

public:
    WordDocument(std::string c) : content(c) {}

    Document* clone() const override {
        return new WordDocument(*this); 
    }

    void print() const override {
        std::cout << "Word Document Content: " << content << std::endl;
    }
};


int main() {
    std::map<std::string, Document*> docRegistry;

    docRegistry["pdf_template"] = new PdfDocument("Standard PDF Template");
    docRegistry["word_template"] = new WordDocument("Standard Word Template");

    Document* clonedPdf = docRegistry["pdf_template"]->clone();
    clonedPdf->print(); 
    delete clonedPdf;

    Document* clonedWord = docRegistry["word_template"]->clone();
    clonedWord->print();
    delete clonedWord;
    for (auto& entry : docRegistry) {
        delete entry.second;
    }

    return 0;
}