#include <fstream>
using namespace std;
class RelationshipMapping
{
private:
    struct Relation
    {
        string entity1;
        string entity2;
    };

    Relation *relationships;
    int capacity;
    int size;

    void resize()
    {
        capacity *= 2;
        Relation *newRelationships = new Relation[capacity];
        for (int i = 0; i < size; ++i)
        {
            newRelationships[i] = relationships[i];
        }
        delete[] relationships;
        relationships = newRelationships;
    }

public:
    RelationshipMapping()
    {
        capacity = 10;
        size = 0;
        relationships = new Relation[capacity];
    }

    ~RelationshipMapping()
    {
        delete[] relationships;
    }

    void addRelation(string entity1, string entity2)
    {
        if (size == capacity)
        {
            resize();
        }
        relationships[size].entity1 = entity1;
        relationships[size].entity2 = entity2;
        size++;
    }

    bool findRelation(string entity1, string entity2)
    {
        for (int i = 0; i < size; i++)
        {
            if ((relationships[i].entity1 == entity1 && relationships[i].entity2 == entity2) ||
                (relationships[i].entity1 == entity2 && relationships[i].entity2 == entity1))
            {
                return true;
            }
        }
        return false;
    }
    void loadFromFile(const string &filename)
    {
        ifstream inFile(filename);
        string line;

        while (getline(inFile, line))
        {
            size_t delimiterPos = line.find(';');
            if (delimiterPos != string::npos)
            {
                string entity1 = line.substr(0, delimiterPos);
                string entity2 = line.substr(delimiterPos + 1);

                // Thêm quan hệ vào ánh xạ
                addRelation(entity1, entity2);
            }
        }

        inFile.close();
    }
    void saveNewRelation(const string &filename, const string &entity1, const string &entity2)
    {
        ofstream outFile(filename, ios::app); // Mở file ở chế độ thêm
        outFile << entity1 << ";" << entity2 << "\n";
        outFile.close();
    }

    void saveToFile(string filename)
    {
        ofstream outFile(filename, ios::app);
        for (int i = 0; i < size; i++)
        {
            outFile << relationships[i].entity1 << ";" << relationships[i].entity2 << "\n";
        }
        outFile.close();
    }
};
