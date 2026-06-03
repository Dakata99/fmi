#include "FileInputStream.h"
#include "FileOutputStream.h"
#include "FileStream.h"
#include "MemoryStream.h"
#include "CopyProcessor.h"
#include "Encryptor.h"
#include "Decryptor.h"
#include "Concatenator.h"
#include "TextSplitter.h"
#include "TextBinder.h"
#include "Duplicator.h"

#include <iostream.h>


void testFIS()
{
    FileInputStream fis("App.cpp");
    
    cout << fis.CanGetLength() << endl;
    cout << fis.CanGetPosition() << endl;
    cout << fis.CanSeek() << endl;
    cout << fis.GetLength() << endl;
    cout << fis.GetPosition() << endl;
    
    unsigned char buf[10];
    int size;
    size = fis.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fis.GetPosition() << endl;

    fis.Seek(100);
    size = fis.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fis.GetPosition() << endl;

    fis.Seek(fis.GetLength() - 5);
    size = fis.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fis.GetPosition() << endl;

    FileInputStream fis1("App.cXX");
    cout << fis1.CanGetLength() << endl;
    cout << fis1.CanGetPosition() << endl;
    cout << fis1.CanSeek() << endl;
    cout << fis1.GetLength() << endl;
    cout << fis1.GetPosition() << endl;
}

void testFOS()
{
    FileOutputStream fos("FOS.txt");
    
    cout << fos.CanGetLength() << endl;
    cout << fos.CanGetPosition() << endl;
    cout << fos.CanSeek() << endl;
    cout << fos.GetLength() << endl;
    cout << fos.GetPosition() << endl;
    
    unsigned char buf[10]={'0','1','2','3','4',
                           '5','6','7','8','9'};
    int size;
    size = fos.Write(buf, 10);
    cout << size << ' ' << endl;
    cout << fos.GetPosition() << endl;
    fos.Flush();

    fos.Seek(5);
    size = fos.Write(buf, 10);
    cout << size << endl;
    cout << fos.GetPosition() << endl;
    cout << fos.GetLength() << endl;

    cout << fos.CanGetLength() << endl;
    cout << fos.CanGetPosition() << endl;
    cout << fos.CanSeek() << endl;

    FileOutputStream fos1("FOS.txt");
    
    cout << fos1.CanGetLength() << endl;
    cout << fos1.CanGetPosition() << endl;
    cout << fos1.CanSeek() << endl;
    cout << fos1.GetLength() << endl;
    cout << fos1.GetPosition() << endl;
}

void testFS()
{
    FileStream fs("App.cpp");
    
    cout << fs.CanGetLength() << endl;
    cout << fs.CanGetPosition() << endl;
    cout << fs.CanSeek() << endl;
    cout << fs.GetLength() << endl;
    cout << fs.GetPosition() << endl;
    
    unsigned char buf[10];
    int size;
    size = fs.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fs.GetPosition() << endl;

    fs.Seek(100);
    size = fs.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fs.GetPosition() << endl;

    fs.Seek(fs.GetLength() - 5);
    size = fs.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fs.GetPosition() << endl;

    FileStream fs2("FS.txt");
    
    cout << fs2.CanGetLength() << endl;
    cout << fs2.CanGetPosition() << endl;
    cout << fs2.CanSeek() << endl;
    cout << fs2.GetLength() << endl;
    cout << fs2.GetPosition() << endl;
    
    unsigned char buf1[10]={'0','1','2','3','4',
                           '5','6','7','8','9'};
    size = fs2.Write(buf1, 10);
    cout << size << ' ' << endl;
    cout << fs2.GetPosition() << endl;
    fs2.Flush();
    size = fs2.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << fs2.GetPosition() << endl;

    fs2.Seek(5);
    size = fs2.Write(buf, 10);
    cout << size << endl;
    cout << fs2.GetPosition() << endl;
    cout << fs2.GetLength() << endl;

    cout << fs2.CanGetLength() << endl;
    cout << fs2.CanGetPosition() << endl;
    cout << fs2.CanSeek() << endl;
}

void testCopy()
{
    FileInputStream src("App.cpp");
    FileOutputStream dest("Copy.cpp");
    CopyProcessor(&src, &dest).Process();
}

void testEncDec()
{
    FileInputStream src("App.cpp");
    FileOutputStream res("App.enc");
    Encryptor enc(&res, "TestWord");
    CopyProcessor(&src, &enc).Process();

    FileInputStream enc_src("App.enc");
    FileOutputStream dest("Copy.cpp");
    Decryptor dec(&enc_src, "TestWord");
    CopyProcessor(&dec, &dest).Process();
}

void testMS()
{
    FileInputStream src("App.cpp");
    MemoryStream res;
    Encryptor enc(&res, "TestWord");
    CopyProcessor(&src, &enc).Process();

    res.Seek(0);
    FileOutputStream dest("Copy.cpp");
    Decryptor dec(&res, "TestWord");
    CopyProcessor(&dec, &dest).Process();

    unsigned char buf[10];
    int size;
    dec.Seek(5);
    size = dec.Read(buf, 9);
    buf[size] = 0;
    cout << size << ' ' << (char*)buf << endl;
    cout << dec.GetPosition() << endl;
}

void testConcat()
{
    FileStream f1("App.cpp");
    FileStream f2("App.cpp");
    FileStream fd("merge.txt");
    CopyProcessor(&Concatenator(&f1, &f2), &fd).Process();
}

void testSplit()
{
    FileOutputStream f1("left.txt");
    FileOutputStream f2("right.txt");
    FileInputStream fs("App.cpp");
    CopyProcessor(&fs, &TextSplitter(&f1, &f2)).Process();
}

void testBind()
{
    FileInputStream f1("left.txt");
    FileInputStream f2("right.txt");
    FileOutputStream fd("copy.cpp");
    CopyProcessor(&TextBinder(&f1, &f2), &fd).Process();
}


//Примерите от програмата
void copy()
{
    FileInputStream input("test.dat");
    FileOutputStream output("test2.dat");
    CopyProcessor(&input, &output).Process();
}

void code()
{
    FileInputStream input("test.dat");
    FileOutputStream output("test2.dat");
    Encryptor encryptor(&output, "Keyword");
    CopyProcessor(&input, &encryptor).Process();
}

void decode()
{
    FileInputStream input("test.dat");
    FileOutputStream output("test2.dat");
    Decryptor decryptor(&input, "Keyword");
    CopyProcessor(&decryptor, &output).Process();
}

void concat()
{
    FileInputStream input1("test1.dat");
    FileInputStream input2("test2.dat");
    FileOutputStream output("test3.dat");
    Concatenator concat(&input1, &input2);
    CopyProcessor(&concat, &output).Process();
}

void split()
{
    FileInputStream input("test1.dat");
    FileOutputStream output1("test2.dat");
    FileOutputStream output2("test3.dat");
    TextSplitter splitter(&output1, &output2);
    CopyProcessor(&input, &splitter).Process();
}

void bind()
{
    FileInputStream input1("test1.dat");
    FileInputStream input2("test2.dat");
    FileOutputStream output("test3.dat");
    TextBinder binder(&input1, &input2);
    CopyProcessor(&binder, &output).Process();
}

void encode2()
{
    FileStream stream("test.dat");
    MemoryStream ms;
    Encryptor encryptor(&ms, "Keyword");
    CopyProcessor(&stream, &encryptor).Process();
    ms.Seek(0);
    CopyProcessor(&ms, &stream).Process();
}

void concat_encode()
{
    FileInputStream input1("test1.dat");
    FileInputStream input2("test2.dat");
    Decryptor decryptor(&input1, "Keyword");
    Concatenator concat(&decryptor, &input2);
    FileOutputStream output1("test3.dat");
    FileOutputStream output2("test4.dat");
    Duplicator duplicator(&output1, &output2);
    Encryptor encryptor(&duplicator, "Keyword");
    CopyProcessor(&concat, &encryptor).Process();
}

int main()
{
    testSplit();
    testBind();
    return 0;
}
