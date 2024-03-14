#include "funkcijos1.h"

int main() {

    srand(time(nullptr));                                       /// inicializuoja atsitiktinių skaičių generatorių naudojant dabartinį laiką kaip pradinį numerį

    int meniu;
    int meniu_duomenu_ivedimui;
    int studSk;
    bool baigti = false;
    bool baigti_duom_ived = false;
    vector <studentas> var, kursiokai; 
    list <studentas> varList, kursiokaiList; 
                                      

    do
    { 
        cout<<"Pasirinkite kaip dirbsite su duomenimis:"<<endl;
        cout<<"1 - domenu ivedimas"<<endl;
        cout<<"2 - duomenu skaitymas is failo"<<endl;
        cout<<"3 - programos laiko testavimas naudojant failu generavima"<<endl;
        cout<<"4 - failu rusiavimas"<<endl;
        cout<<"5 - baigti darba"<<endl;
        cout<<"--------------------------------------------------------"<<endl;
        
            try {
                cout << "Iveskite pasirinkima: " << endl;
                string input;
                cin >> input;

                if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                throw invalid_argument("Netinkamas pasirinkimas");
                }

                meniu = stoi(input);

                if (meniu < 1 || meniu > 4) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 3
                    throw invalid_argument("Klaida! Iveskite nuo 1 iki 4 ");
                }
                            
            } 
                        
            catch (const invalid_argument & e) {
                cerr << "Klaida: " << e.what() << endl;
                cout << endl;

                continue;
            }    

        switch (meniu)                                                                                  /// meniu skirtas v0.2
        {
            case 1:
            
                cout<<"Duomenu ivedimui pasirinkite buda: "<<endl;
                do
                    {
                    cout<<"1 - ivedimas ranka"<<endl;
                    cout<<"2 - generuoti pazymius"<<endl;
                    cout<<"3 - generuoti ir pazymius ir studentu vardus, pavardes"<<endl;
                    cout<<"4 - baigti darba"<<endl;
                    cout<<"--------------------------------------------------------"<<endl;
                    
                    
                    try {
                        cout << "Iveskite pasirinkima: " << endl;
                        string input;
                        cin >> input;

                        if (input.find_first_not_of("0123456789") != string::npos) {                                  ///tikrina ar ivestas skaicius naturalusis
                        throw invalid_argument("Netinkamas pasirinkimas");
                        }

                        meniu = stoi(input);

                        if (meniu < 1 || meniu > 4) {                                                                ///tikrina ar ivestas skaicius yra nuo 1 iki 4
                            throw invalid_argument("Iveskite nuo 1 iki 4 ");
                        }
                                    
                    } 
                            
                    catch (const invalid_argument & e) {
                        cerr << "Klaida: " << e.what() << endl;
                        cout << endl;
                        continue;
                    }
                    
                switch (meniu)                                                      ///meniu skirtas v0.1
                        {
                            case 1:
                                var.clear();
                                ivedimasRanka(var,studSk);
                                spausdinimas(var);
                                cout<<endl;
                                break;
                            case 2:
                                var.clear();
                                atsitiktiniaiPazymiai(var, studSk);
                                spausdinimas(var);
                                cout<<endl;            
                                break;
                            case 3:
                                var.clear();
                                atsitiktiniaiPazVar(var, studSk);
                                spausdinimas( var);
                                cout<<endl;
                                break;
                            case 4:
                                cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
                                baigti=true;
                                break;
                            default:
                                cout<< "Iveskite nuo 1 iki 4 " << endl;

                                break;
                        }

                    } while (!baigti);
            break;

        case 2:
            su_duomenimis_is_failu(kursiokai, var);
            break;

        case 3:
            testavimui(var);
            break;

        case 4:
            // testFail(var);
            testFail_list(varList);

        
        case 5:
            cout<<"Darbas su duomenu ivedimu baigtas\n"<<endl;
            baigti=true;
            break;

        default:
            cout<< "Iveskite nuo 1 iki 5 " << endl;

            break;
        
        }

    } while (!baigti);


    return 0;
}
