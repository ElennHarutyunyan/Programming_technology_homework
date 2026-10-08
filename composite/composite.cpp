#include <iostream>
#include <vector>
#include <string>

class FileSystemComponent {
public:
    virtual void display() const = 0;
    virtual ~FileSystemComponent() {}
};

class File : public FileSystemComponent {
private:
    std::string name;

public:
    File(std::string n) : name(n) {}

    void display() const override {
        std::cout << "File: " << name << std::endl;
    }
};

class Directory : public FileSystemComponent {
private:
    std::string name;
    std::vector<FileSystemComponent*> children; 

public:
    Directory(std::string n) : name(n) {}

    void add(FileSystemComponent* component) {
        children.push_back(component);
    }

    void display() const override {
        std::cout << "Directory: " << name << std::endl;
        for (const auto& child : children) {
            std::cout << "  - ";
            child->display(); 
        }
    }


    ~Directory() {
        for (auto child : children) {
            delete child;
        }
    }
};

int main() {
    FileSystemComponent* file1 = new File("document.txt");
    FileSystemComponent* file2 = new File("photo.png");
    FileSystemComponent* file3 = new File("song.mp3");

    Directory* rootDir = new Directory("RootFolder");

    Directory* subDir = new Directory("SubFolder");
    

    subDir->add(file2);
    subDir->add(file3);

    rootDir->add(file1);
    rootDir->add(subDir);

    rootDir->display();
    delete rootDir;

    return 0;
}