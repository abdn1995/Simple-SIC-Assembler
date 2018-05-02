#include <bits/stdc++.h>
using namespace std;
//ERRORS
string FOERR = "Can't open the required file"; //file open error
string CERR = "Can't find the required code"; //code search error
string UERR = "Unknown error";
string SERR = "Syntax error in line ";
string ALE="Address Limit Exceeded ";
int X=0;
vector <int> xl;
string q="'";
string PName="       ";
string Saddress="    ";
string Plen="    ";
string Len(string S,string E)
{
    string Length;
    stringstream temp;
    int x,y,L;
    x = (int)strtoul(S.c_str(),0,16);
    y = (int)strtoul(E.c_str(),0,16);
    L=y-x;
    temp<<hex<<L;
    temp>>Length;
    for(auto& x: Length)
        x = toupper(x);
    return Length;
}
string Address_Gen(string Address,string inc,int v)
{
    string NewAddress;
    stringstream temp;
    int x,y,NAS,i;
    int AS=Address.size();
    int IS=inc.size();
    for (i=0; i<AS; )
    {
        if (Address[i]!='*' || Address[i]!=' ')
            i++;
        else
        {
            if (Address[i]=='*' || Address[i]==' ')
            {
                Address[i]='\0';
                i++;
            }
        }
    }
    for (i=0; i<IS; )
    {
        if (inc[i]!='*')
            i++;
        else
        {
            if (inc[i]=='*')
            {
                inc[i]='\0';
                i++;
            }
        }
    }
    x = (int)strtoul(Address.c_str(),0,16);
    y = (int)strtoul(inc.c_str(),0,10);
    x+=y*v;
    if (x>32768)
    {
        cout<<ALE<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    temp<<hex<<x;
    temp>>NewAddress;
    NAS=NewAddress.size();
    if (NAS>0 && NAS<5)
    {
        if (NAS==1)
        {
            NewAddress="000"+NewAddress;
            for(auto& x: NewAddress)
                x = toupper(x);
            return NewAddress;
        }
        else if (NAS==2)
        {
            NewAddress="00"+NewAddress;
            for(auto& x: NewAddress)
                x = toupper(x);
            return NewAddress;
        }
        else if (NAS==3)
        {
            NewAddress='0'+NewAddress;
            for(auto& x: NewAddress)
                x = toupper(x);
            return NewAddress;
        }
        else
        {
            for(auto& x: NewAddress)
                x = toupper(x);
            return NewAddress;
        }
    }
    else
    {
        return ALE;
    }
}
int IN_OP(string OP)
{
    fstream OPTAB;
    string t= "";
    int OPS=OP.size();
    for(auto& x: OP)
        x = toupper(x);
    int x=OPS;
    for (int i=0; i<OPS; )
    {
        if (OP[i]!=' ')
            i++;
        else
        {
            if (OP[i]==' ')
            {
                OP[i]='\0';
                i++;
                x--;
            }
        }
    }
    OPTAB.open("OPTAB.txt");
    if(OPTAB.fail())
    {
        return 0;
    }
    bool isFound=0;
    while(!OPTAB.eof())
    {
        getline(OPTAB,t);
        for(int i=0; i<x; i++)
        {
            if(t[i]==OP[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
        }
        if(isFound)
        {
            return 1;
        }

    }
    if(OPTAB.eof() && (!isFound))
    {
        return 0;
    }
    OPTAB.close();
    return 0;
}
string OP(string OP)
{
    fstream OPTAB;
    string code="  ",t= "";
    int OPS=OP.size();
    for(auto& x: OP)
        x = toupper(x);
    int x=OPS;
    for (int i=0; i<OPS; )
    {
        if (OP[i]!=' ')
            i++;
        else
        {
            if (OP[i]==' ')
            {
                OP[i]='\0';
                i++;
                x--;
            }
        }
    }
    OPTAB.open("OPTAB.txt");
    if(OPTAB.fail())
    {
        cout<<FOERR<<"'OPTAB IN FN OP'"<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    bool isFound=0;
    while(!OPTAB.eof())
    {
        getline(OPTAB,t);
        for(int i=0; i<x; i++)
        {
            if(t[i]==OP[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
        }
        int ts=t.size();
        if(isFound)
        {
            for(int i = x; i<ts; i++)
                code[i-(x)] = t[i];
            return code;
        }

    }
    if(OPTAB.eof()&&(!isFound))
    {
        cout<<CERR<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    OPTAB.close();

    cout<<UERR<<endl;
    cout<<"Enter (E + Enter) to exit"<<endl;
    getchar();
    exit(1);
}
string SYM(string sym)
{
    ifstream SYMTAB;
    string LOC="    ",t= "";
    int SYMS=0;
    SYMS=sym.length();
    int x=SYMS;
    for (int i=0; i<SYMS; )
    {
        if (sym[i]!=' ' && sym[i]!=',')
            i++;
        else
        {
            if (sym[i]==' ' || sym[i]==',')
            {
                sym[i]='\0';
                i++;
                x--;
            }
        }
    }
    SYMTAB.open("SYMTAB.txt");
    if(SYMTAB.fail())
    {
        cout<<FOERR<<"'SYMTAB IN FN SYM'"<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    bool isFound=0;
    while(!SYMTAB.eof())
    {
        getline(SYMTAB,t);
        for(int i=0; i<x; i++)
        {
            if(t[i]==sym[i])
                isFound = 1;
            else
            {
                isFound =0;
                break;
            }
        }
        if(isFound)
        {
            int ts=t.size();
            for(int i = x; i<ts; i++)
            {
                LOC[i-(x)] = t[i];
            }
            goto E;
        }
    }
    SYMTAB.close();
E:
    return LOC;
}
void pass1()
{
    ifstream SRC;
    ofstream SYMTAB;
    ofstream TMP;
    int line =1,TS=0,i=0,j=0,k=0;
    string LCCTR="****",temp = "",increment="0001";
    SRC.open("SRC.txt");
    if(SRC.fail())
    {
        cout<< FOERR<<"'SRC'"<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    TMP.open("TMP.txt");
    SYMTAB.open("SYMTAB.txt");
    if(TMP.fail() || SYMTAB.fail())
    {
        cout<< FOERR<<"'TMP OR SYMTAB'"<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    while(!SRC.eof())
    {
loop1:
        getline(SRC,temp);
        TS=temp.size();
        if (temp[0]=='.')
        {
            TMP<<temp<<endl;
            line++;
            goto loop1;
        }
        else if (line==1)
        {
            for(i=0; i<TS; i++)
            {
                if (i<7 && temp[0]!=' ')
                {
                    PName[i]=temp[i];
                }
                else if (i==7 && temp[i]==' ')
                {
                    i++;
                    if (temp[i]=='S' || temp[i]=='s')
                    {
                        if (temp[i+1]=='T' || temp[i+1]=='t')
                        {
                            if (temp[i+2]=='A' || temp[i+2]=='a')
                            {
                                if (temp[i+3]=='R' || temp[i+3]=='r')
                                {
                                    if (temp[i+4]=='T' || temp[i+4]=='t')
                                    {
                                        i+=7;
                                        if (temp[i]!=' ' && i==15)
                                        {
                                            for (k=0; k<(TS-i); k++)
                                                LCCTR[k]=temp[i+k];
                                            Saddress=LCCTR;
                                            LCCTR=Address_Gen(LCCTR,"0000",0);
                                            TMP<<LCCTR<<"     "<<PName<<" "<<"START  "<<LCCTR<<endl;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    cout<<SERR<<"\t"<<line<<endl;
                    cout<<"Enter (E + Enter) to exit"<<endl;
                    getchar();
                    exit(1);
                }
            }
        }
        else
        {
            int SYMF=0;
            for(i=0; i<TS; i++)
            {
                if (temp[0]==' ' && SYMF==0)
                {
                    for (j=1; j<8; j++)
                    {
                        if (temp[j]!=' ')
                        {
                            cout<<SERR<<"\t"<<line<<endl;
                            cout<<"Enter (E + Enter) to exit"<<endl;
                            getchar();
                            exit(1);
                        }
                    }
                }
                else if (temp[0]!=0 && SYMF==0)
                    SYMF=1;
                if (i==8)
                {
                    string op="****";
                    for (j=i; j<(i+4); j++)
                    {
                        op[j-i]=temp[j];
                    }
                    if (SYMF==1 && IN_OP(op)==1)
                    {
                        for (j=i-8; j<8; j++)
                        {
                            if (temp[j]!=' ' && j<8)
                                SYMTAB<<temp[j];
                            if (j==7)
                                SYMTAB<<LCCTR<<endl;
                        }
                        TMP<<LCCTR<<"     "<<temp<<endl;
                        LCCTR=Address_Gen(LCCTR,increment,3);
                    }
                    else if (SYMF==1 && (temp[i]=='R' || temp[i]=='r'))
                    {
                        if (temp[i+1]=='E' || temp[i+1]=='e')
                        {
                            if (temp[i+2]=='S' || temp[i+2]=='s')
                            {
                                if (temp[i+3]=='W' || temp[i+3]=='w')
                                {
                                    TMP<<LCCTR<<"     "<<temp<<endl;
                                    string RES="*****";
                                    for (j=15; j<TS; j++)
                                    {
                                        RES[j-15]=temp[j];
                                    }
                                    for (j=i-8; j<8; j++)
                                    {
                                        if (temp[j]!=' ' && j<8)
                                            SYMTAB<<temp[j];
                                        if (j==7)
                                            SYMTAB<<LCCTR<<endl;
                                    }
                                    LCCTR=Address_Gen(LCCTR,RES,3);
                                }
                                else if (temp[i+3]=='B' || temp[i+3]=='b')
                                {
                                    TMP<<LCCTR<<"     "<<temp<<endl;
                                    string RES="*****";
                                    for (j=15; j<TS; j++)
                                    {
                                        RES[j-15]=temp[j];
                                    }
                                    for (j=i-8; j<8; j++)
                                    {
                                        if (temp[j]!=' ' && j<8)
                                            SYMTAB<<temp[j];
                                        if (j==7)
                                            SYMTAB<<LCCTR<<endl;
                                    }
                                    LCCTR=Address_Gen(LCCTR,RES,1);
                                }
                                else
                                {
                                    cout<<SERR<<"\t"<<line<<endl;
                                    cout<<"Enter (E + Enter) to exit"<<endl;
                                    getchar();
                                    exit(1);
                                }
                            }
                            else
                            {
                                cout<<SERR<<"\t"<<line<<endl;
                                cout<<"Enter (E + Enter) to exit"<<endl;
                                getchar();
                                exit(1);
                            }
                        }
                        else
                        {
                            cout<<SERR<<"\t"<<line<<endl;
                            cout<<"Enter (E + Enter) to exit"<<endl;
                            getchar();
                            exit(1);;
                        }
                    }
                    else if (SYMF==1 && (temp[i]=='W' || temp[i]=='w'))
                    {
                        if (temp[i+1]=='O' || temp[i+1]=='o')
                        {
                            if (temp[i+2]=='R' || temp[i+2]=='r')
                            {
                                if (temp[i+3]=='D' || temp[i+3]=='d')
                                {
                                    TMP<<LCCTR<<"     "<<temp<<endl;
                                    for (j=i-8; j<8; j++)
                                    {
                                        if (temp[j]!=' ' && j<8)
                                            SYMTAB<<temp[j];
                                        if (j==7)
                                            SYMTAB<<LCCTR<<endl;
                                    }
                                    LCCTR=Address_Gen(LCCTR,increment,3);
                                }
                                else
                                {
                                    cout<<SERR<<"\t"<<line<<endl;
                                    cout<<"Enter (E + Enter) to exit"<<endl;
                                    getchar();
                                    exit(1);
                                }
                            }
                            else
                            {
                                cout<<SERR<<"\t"<<line<<endl;
                                cout<<"Enter (E + Enter) to exit"<<endl;
                                getchar();
                                exit(1);
                            }
                        }
                        else
                        {
                            cout<<SERR<<"\t"<<line<<endl;
                            cout<<"Enter (E + Enter) to exit"<<endl;
                            getchar();
                            exit(1);
                        }
                    }
                    else if (SYMF==1 && (temp[i]=='B' || temp[i]=='b'))
                    {
                        if (temp[i+1]=='Y' || temp[i+1]=='y')
                        {
                            if (temp[i+2]=='T' || temp[i+2]=='t')
                            {
                                if (temp[i+3]=='E' || temp[i+3]=='e')
                                {
                                    j=15;
                                    if (temp[j]=='X' || temp[j]=='x')
                                    {
                                        j++;
                                        if (temp[j]==q[0] && temp[j+3]==q[0])
                                        {
                                            TMP<<LCCTR<<"     "<<temp<<endl;
                                            for (k=i-8; k<8; k++)
                                            {
                                                if (temp[k]!=' ' && k<7)
                                                    SYMTAB<<temp[k];
                                                if (k==7)
                                                    SYMTAB<<LCCTR<<endl;
                                            }
                                            LCCTR=Address_Gen(LCCTR,increment,1);
                                        }
                                    }
                                    else if (temp[j]=='C' || temp[j]=='c')
                                    {
                                        j++;
                                        string q="'";
                                        int var;
                                        if (temp[j]==q[0])
                                        {
                                            j++;
                                            for (k=j; k<TS; k++)
                                            {
                                                if (temp[k]==q[0])
                                                {
                                                    break;
                                                }
                                            }
                                            var=k-j;
                                            TMP<<LCCTR<<"     "<<temp<<endl;
                                            for (k=i-8; k<8; k++)
                                            {
                                                if (temp[k]!=' ' && k<8)
                                                    SYMTAB<<temp[k];
                                                if (k==7)
                                                    SYMTAB<<LCCTR<<endl;
                                            }
                                            LCCTR=Address_Gen(LCCTR,increment,var);
                                        }
                                    }
                                    else
                                    {
                                        cout<<SERR<<"\t"<<line<<endl;
                                        cout<<"Enter (E + Enter) to exit"<<endl;
                                        getchar();
                                        exit(1);
                                    }
                                }
                                else
                                {
                                    cout<<SERR<<"\t"<<line<<endl;
                                    cout<<"Enter (E + Enter) to exit"<<endl;
                                    getchar();
                                    exit(1);
                                }
                            }
                        }
                        else
                        {
                            cout<<SERR<<"\t"<<line<<endl;
                            cout<<"Enter (E + Enter) to exit"<<endl;
                            getchar();
                            exit(1);
                        }
                    }
                    else if (SYMF==0 && IN_OP(op)==1)
                    {
                        for(auto& x: op)
                            x = toupper(x);
                        if (op=="END ")
                        {
                            TMP<<LCCTR<<"     "<<temp;
                            Plen=Len(Saddress,LCCTR);
                        }
                        else
                        {
                            TMP<<LCCTR<<"     "<<temp<<endl;
                            LCCTR=Address_Gen(LCCTR,increment,3);
                        }
                    }
                    else
                    {
                        cout<<SERR<<"\t"<<line<<endl;
                        cout<<"Enter (E + Enter) to exit"<<endl;
                        getchar();
                        exit(1);
                    }
                }
                if(temp[i]==',')
                {
                    if (temp[i+1]=='X' || temp[i+1]=='x')
                    {
                        xl.push_back(line);
                        X++;
                    }
                    else
                    {
                        cout<<SERR<<"\t"<<line<<endl;
                        cout<<"Enter (E + Enter) to exit"<<endl;
                        getchar();
                        exit(1);
                    }
                }
            }
        }
        line++;
    }
    SRC.close();
    SYMTAB.close();
    TMP.close();
    cout<<"PASS 1 A SUCCESS"<<endl;
}
string Value_Gen(string Value)
{
    string NewValue;
    stringstream temp;
    int y,NVS,i;
    int VS=Value.size();
    for (i=0; i<VS; )
    {
        if (Value[i]!=' ')
            i++;
        else
        {
            if (Value[i]==' ')
            {
                Value[i]='\0';
                i++;
            }
        }
    }
    y = (int)strtoul(Value.c_str(),0,10);
    temp<<hex<<y;
    temp>>NewValue;
    NVS=NewValue.size();
    if (NVS>0 && NVS<5)
    {
        if (NVS==1)
        {
            NewValue="000"+NewValue;
            for(auto& x: NewValue)
                x = toupper(x);
            return NewValue;
        }
        else if (NVS==2)
        {
            NewValue="00"+NewValue;
            for(auto& x: NewValue)
                x = toupper(x);
            return NewValue;
        }
        else if (NVS==3)
        {
            NewValue='0'+NewValue;
            for(auto& x: NewValue)
                x = toupper(x);
            return NewValue;
        }
    }
    for(auto& x: NewValue)
        x = toupper(x);
    return NewValue;
}
string indexing(string Value)
{
    string NewValue;
    stringstream temp;
    int x,i;
    int VS=Value.size();
    for (i=0; i<VS; )
    {
        if (Value[i]!=' ')
            i++;
        else
        {
            if (Value[i]==' ')
            {
                Value[i]='\0';
                i++;
            }
        }
    }
    x = (int)strtoul(Value.c_str(),0,16);
    x+=32768;
    temp<<hex<<x;
    temp>>NewValue;
    return NewValue;
}
bool is_in_vec(int v)
{
    for (int i=0; i<X; i++)
    {
        if (xl[i]==v)
            return true;
    }
    return false;
}
void pass2()
{
    ifstream TMP;
    ofstream LF;
    ofstream OBJ;
    int line=1,j=0;
    string temp="";
    TMP.open("TMP.txt");
    LF.open("Listing_File.txt");
    OBJ.open("Object_File.txt");
    if(LF.fail() || TMP.fail() || OBJ.fail())
    {
        cout<< FOERR<<"'LF, TMP, OR OBJ IN PASS 2'"<<endl;
        cout<<"Enter (E + Enter) to exit"<<endl;
        getchar();
        exit(1);
    }
    while(!TMP.eof())
    {
loop2:
        getline(TMP,temp);
        if (temp[0]=='.')
        {
            LF<<temp<<endl;
            line++;
            goto loop2;
        }
        else if (line==1)
        {
            line++;
            LF<<"           "<<temp<<endl;
            OBJ<<"H|"<<PName<<"|00"<<Saddress<<"|00"<<Plen<<endl;
            goto loop2;
        }
        else if (line>1)
        {
            string loc="    ";
            string op="    ";
            string label="       ";
            for (j=17; j<21; j++)
            {
                op[j-17]=temp[j];
            }
            int ts=0;
            for(auto& x: op)
                x = toupper(x);
            ts=temp.size();
            for (j=24; j<ts; j++)
            {
                label[j-24]=temp[j];
            }
            if (is_in_vec(line)==true)
            {
                label=SYM(label);
                LF<<OP(op)<<indexing(label)<<"     "<<temp<<endl;
                line++;
                for (j=0; j<4; j++)
                    loc[j]=temp[j];
                OBJ<<"T|00"<<loc<<"|03|"<<OP(op)<<indexing(label)<<endl;
                goto loop2;
            }
            else
            {
                if (op=="RSUB")
                {
                    LF<<OP(op)<<"0000"<<"     "<<temp<<endl;
                    line++;
                    for (j=0; j<4; j++)
                        loc[j]=temp[j];
                    OBJ<<"T|00"<<loc<<"|03|"<<OP(op)<<"0000"<<endl;
                    goto loop2;
                }
                else if (op=="WORD")
                {
                    LF<<"00"<<Value_Gen(label)<<"     "<<temp<<endl;
                    line++;
                    for (j=0; j<4; j++)
                        loc[j]=temp[j];
                    OBJ<<"T|00"<<loc<<"|03|"<<"00"<<Value_Gen(label)<<endl;
                    goto loop2;
                }
                else if (op=="BYTE")
                {
                    int lbs=label.size();
                    for (j=0; j<lbs; j++)
                    {
                        if(label[j]=='X' || label[j]=='x')
                        {
                            LF<<"0000"<<label[j+2]<<label[j+3]<<"     "<<temp<<endl;
                            line++;
                            for (int k=0; k<4; k++)
                                loc[k]=temp[k];
                            OBJ<<"T|00"<<loc<<"|03|"<<"0000"<<label[j+2]<<label[j+3]<<endl;
                            goto loop2;
                        }
                        else if (label[j]=='C' || label[j]=='c')
                        {
                            string value;
                            stringstream t;
                            for (j=2; j<lbs; j++)
                            {
                                if (label[j]==q[0])
                                    break;
                                else
                                    t<<hex<<(int)label[j];
                            }
                            t>>value;
                            LF<<value<<"     "<<temp<<endl;
                            line++;
                            for (j=0; j<4; j++)
                                loc[j]=temp[j];
                            OBJ<<"T|00"<<loc<<"|03|"<<value<<endl;
                            goto loop2;
                        }
                    }
                }
                else if (op=="RESW")
                {
                    LF<<"           "<<temp<<endl;
                    line++;
                    goto loop2;
                }
                else if (op=="RESB")
                {
                    LF<<"           "<<temp<<endl;
                    line++;
                    goto loop2;
                }
                else if (op=="END ")
                {
                    LF<<"           "<<temp;
                    OBJ<<"E|00"<<Saddress;
                }
                else
                {
                    LF<<OP(op)<<SYM(label)<<"     "<<temp<<endl;
                    line++;
                    for (j=0; j<4; j++)
                        loc[j]=temp[j];
                    OBJ<<"T|00"<<loc<<"|03|"<<OP(op)<<SYM(label)<<endl;
                    goto loop2;
                }
            }
        }
    }
    cout<<"PASS 2 A SUCCESS"<<endl<<"SUCCESSFUL ASSEMBLY"<<endl;
    TMP.close();
    LF.close();
    OBJ.close();
    remove("TMP.txt");
}
int main()
{
    pass1();
    pass2();
    cout<<"Enter (E + Enter) to exit"<<endl;
    getchar();
    exit(1);
    return 0;
}
