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
    Sample* sortedArray = new Sample[fileSize];

    for (int i = 0; i < fileSize; i++)
    {
        count[array[i].speciesCode]++;
    }

    for (int i = 1; i < 5; i++)
    {
        count[i] += count[i - 1];
    }

    for (int i = fileSize - 1; i >= 0; i--)
    {
        int speciesCode = array[i].speciesCode;
        count[speciesCode]--;
        sortedArray[count[speciesCode]] = array[i];
    }

    for (int i = 0; i < fileSize; i++)
    {
        array[i] = sortedArray[i];
    }

    delete[] sortedArray;
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
    Sample sample1;
    
    file.open(filename, ios::in | ios::binary);

    file.seekg(offset * sizeof(Sample), ios::beg);
    file.read((char*)&sample1, sizeof(Sample));

    if (file.gcount() == sizeof(Sample) && sample1.speciesCode == speciesCode)
    {
        file.close();
        return true;
    }

    file.close();
    return false;
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
    {
        indexArray[i] = -1;
    }

    for (int i = 0; i < fileSize; i++)
    {
        int speciesCode = array[i].speciesCode;

        if (indexArray[array[i].speciesCode] == -1)
        {
            indexArray[array[i].speciesCode] = i;
        }
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
    Sample sample2;

    file.open(filename, ios::in | ios::binary);

    file.seekg((speciesCode + offset) * sizeof(Sample), ios::beg);

    file.read((char*)&sample2, sizeof(Sample));

    if (file.gcount() == sizeof(Sample) && sample2.speciesCode == speciesCode)
    {
        cout << "Sample: " << sample2.sampleID << endl;
        cout << "Researcher: " << sample2.researcher << endl;
    }

    file.close();

}

void GENE_BANK::p_updateResearcher(int speciesCode, int offset, char* newName, char* filename) 
{
    fstream file;
    Sample sample3;

    file.open(filename, ios::in | ios::out | ios::binary);

    file.seekg((speciesCode + offset) * sizeof(Sample), ios::beg);
    file.read((char*)&sample3, sizeof(Sample));

    if (file.gcount() == sizeof(Sample))
    {
        strcpy(sample3.researcher, newName);

        file.seekp((speciesCode + offset) * sizeof(Sample), ios::beg);
        file.write((char*)&sample3, sizeof(Sample));
    }

    file.close();
}

void GENE_BANK::p_deleteSample(int speciesCode, int offset, char* filename) 
{
    fstream file;
    Sample sample4;

    file.open(filename, ios::in | ios::out | ios::binary);

    file.seekg((speciesCode + offset) * sizeof(Sample), ios::beg);
    file.read((char*)&sample4, sizeof(Sample));

    if (file.gcount() == sizeof(Sample))
    {
        sample4.sampleID = -1;
        file.seekp((speciesCode + offset) * sizeof(Sample), ios::beg);
        file.write((char*)&sample4, sizeof(Sample));
    }

    file.close();
}

void GENE_BANK::p_printRange(int speciesCode, int startIndex, int endIndex, char* filename) 
{
    fstream file;
    Sample sample5;

    file.open(filename, ios::in | ios::binary);

    for (int i = startIndex; i <= endIndex; i++)
    {
        file.seekg((speciesCode + i) * sizeof(Sample), ios::beg);
        file.read((char*)&sample5, sizeof(Sample));

        if (file.gcount() == sizeof(Sample) && sample5.speciesCode == speciesCode)
        {
            if (sample5.sampleID != -1)
            {
                cout << "Sample: " << sample5.sampleID << endl;
                cout << "Species Code: " << sample5.speciesCode << endl;
                cout << "Purity Score: " << sample5.purityScore << endl;
                cout << "Researcher: " << sample5.researcher << endl;
                cout << endl;
            }
        }
    }
    file.close();
}
