#include "geneBank.h"

// =================================== PUBLIC FUNCTIONS =======================================================

GENE_BANK::GENE_BANK() 
{
    this->fileSize = 0;
    this->entryByte = sizeof(Sample);
}

GENE_BANK::~GENE_BANK() 
{
    cout << "Destructing ..." << endl;
}

void GENE_BANK::sort(Sample array[], int fileSize)
{
    int count[5] = {0};
    for (int i = 0; i < fileSize; i++)
        count[array[i].speciesCode]++;

    int startPos[5];
    startPos[0] = 0;
    for (int i = 1; i < 5; i++)
        startPos[i] = startPos[i - 1] + count[i - 1];

    Sample* sorted = new Sample[fileSize];
    int pos[5];
    for (int i = 0; i < 5; i++)
        pos[i] = startPos[i];

    for (int i = 0; i < fileSize; i++)
    {
        int sc = array[i].speciesCode;
        sorted[pos[sc]++] = array[i];
    }

    for (int i = 0; i < fileSize; i++)
        array[i] = sorted[i];

    delete[] sorted;
}

void GENE_BANK::indexSamples(Sample array[], int indexArray[]) 
{
    this->p_index(array, indexArray);
}

void GENE_BANK::displayResearcher(int speciesCode, int offset, char* filename) 
{
    bool checkSample;

    checkSample = searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_displayResearcher(speciesCode, offset, filename);
    } else {
        cout << "Sample record doesn't exist! Can't display researcher name." << endl;
    }
}

bool GENE_BANK::searchSample(int speciesCode, int offset, char* filename) 
{
    fstream file;
    Sample s;

    file.open(filename, ios::in | ios::binary);
    if (!file.is_open())
        return false;

    file.seekg((long long)(speciesCode + offset) * sizeof(Sample), ios::beg);
    file.read((char*)&s, sizeof(Sample));

    bool found = (file.gcount() == sizeof(Sample)) && (s.sampleID != -1);

    file.close();
    return found;
}

void GENE_BANK::updateResearcher(int speciesCode, int offset, char* newName, char* filename) 
{
    bool checkSample;

    checkSample = this->searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_updateResearcher(speciesCode, offset, newName, filename);
    } else {
        cout << "Sample record to be updated doesn't exist!" << endl;
        p_updateResearcher(speciesCode, offset, newName, filename);
    }
}

void GENE_BANK::deleteSample(int speciesCode, int offset, char* filename)
{
    bool checkSample;

    checkSample = this->searchSample(speciesCode, offset, filename);

    if(checkSample){
        p_deleteSample(speciesCode, offset, filename);
    } else {
        cout << "Sample record to be deletesd doesn't exist!" << endl;
    }
}

void GENE_BANK::printSampleRange(int speciesCode, int startIndex, int endIndex, char* filename) 
{
    if(startIndex >= endIndex)
        throw MyException("ERROR: start index is larger than end index!");
    else
        this->p_printRange(speciesCode, startIndex, endIndex, filename);
}

// =================================== PRIVATE FUNCTIONS =======================================================

// your sorting algorithm here

void GENE_BANK::p_index(Sample array[], int indexArray[]) 
{
    for (int i = 0; i < 5; i++)
        indexArray[i] = -1;

    for (int i = 0; i < this->fileSize; i++)
    {
        int sc = array[i].speciesCode;
        if (indexArray[sc] == -1)
            indexArray[sc] = i;
    }
}

void GENE_BANK::p_displayResearcher(int speciesCode, int offset, char* filename) 
{
    /* These are the 5 unique species codes
        0 - H_SAP
        1 - M_MUS
        2 - D_MEL
        3 - E_COL
        4 - A_THA
    */

    fstream file;
    Sample s;

    file.open(filename, ios::in | ios::binary);

    file.seekg((long long)(speciesCode + offset) * sizeof(Sample), ios::beg);
    file.read((char*)&s, sizeof(Sample));

    if (file.gcount() == sizeof(Sample))
    {
        cout << "Sample ID: " << s.sampleID << endl;
        cout << "Species: " << s.speciesCode << endl;
        cout << "Researcher: " << s.researcher << endl;
    }

    file.close();
}

void GENE_BANK::p_updateResearcher(int speciesCode, int offset, char* newName, char* filename) 
{
    fstream file;
    Sample s;

    file.open(filename, ios::in | ios::out | ios::binary);

    long long pos = (long long)(speciesCode + offset) * sizeof(Sample);

    file.seekg(pos, ios::beg);
    file.read((char*)&s, sizeof(Sample));

    if (file.gcount() == sizeof(Sample))
    {
        strncpy(s.researcher, newName, MAX_RESEARCHER_NAME - 1);
        s.researcher[MAX_RESEARCHER_NAME - 1] = '\0';

        file.seekp(pos, ios::beg);
        file.write((char*)&s, sizeof(Sample));
    }
}

void GENE_BANK::p_deleteSample(int speciesCode, int offset, char* filename) 
{
    fstream file;
    Sample s;

    file.open(filename, ios::in | ios::out | ios::binary);

    long long pos = (long long)(speciesCode + offset) * sizeof(Sample);

    file.seekg(pos, ios::beg);
    file.read((char*)&s, sizeof(Sample));

    if (file.gcount() == sizeof(Sample))
    {
        s.sampleID = -1;
        file.seekp(pos, ios::beg);
        file.write((char*)&s, sizeof(Sample));
        cout << "Offset: " << offset << " deleted." << endl;
    }

    file.close();
}

void GENE_BANK::p_printRange(int speciesCode, int startIndex, int endIndex, char* filename) 
{
    fstream file;
    Sample s;

    file.open(filename, ios::in | ios::binary);

    for (int i = startIndex; i <= endIndex; i++)
    {
        file.seekg((long long)(speciesCode + i) * sizeof(Sample), ios::beg);
        file.read((char*)&s, sizeof(Sample));

        if (file.gcount() == sizeof(Sample) && s.sampleID != -1)
        {
            cout << "SampleID: " << s.sampleID << endl;
            cout << "Species Code: " << s.speciesCode << endl;
            cout << "Purity Score: " << s.purityScore << endl;
            cout << "Researcher: " << s.researcher << endl;
            cout << endl;
        }
    }

    file.close();
}
