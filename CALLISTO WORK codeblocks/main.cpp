#include <iostream>
#include <iomanip>

using namespace std;

int i;
int j;
int temp;

bool compare(int* array1, int* array2){
	if ((array1[i] == array2[i]) && array1[i]!= 0){
		//&& array1[i] != NULL
		return 1;
	}
}



int main()
{
//                            0    1      2    3      4    5     6      7    8     9     10    11    12    13    14
	int firstArray[15] =   {0x8d, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
	int secondArray[15] =  {0x8d, 0x02, 0x04, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
	int thirdArray[15] =   {0x8d, 0x01, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
	int lastArray[15] =    {0x8d, 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};

	int FinalArray[15] =   {0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31, 0x31};
                          //0x8d,  0x1,  0x2,  0x8, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d, 0x0,  0x0,

	//herhangi bir esitlik buldugu anda yapistiriyor
	for (i = 0; i<15; i++){
		if( compare(&firstArray[i],&secondArray[i] ) ){
			FinalArray[i] = firstArray[i];
		}
		else if( compare(&firstArray[i],&thirdArray[i] ) ){
			FinalArray[i] = firstArray[i];
		}
		else if( compare(&firstArray[i],&lastArray[i] ) ){
			FinalArray[i] = firstArray[i];
		}
		else if( compare(&secondArray[i],&thirdArray[i] ) ){
			FinalArray[i] = secondArray[i];
		}
		else if( compare(&secondArray[i],&lastArray[i] ) ){
			FinalArray[i] = secondArray[i];
		}
    	else if( compare(&thirdArray[i],&lastArray[i] ) ){
			FinalArray[i] = thirdArray[i];
		}
		else{
            FinalArray[i] = lastArray[i];
		}
		cout << "testerX" << endl;
	}

	//////////////////////PROBLEM BURANIN UZERINDEKI YERDE, final arrayin ilk halini dogrudan first arrayden kopyaliyor/////////////
cout << "En bastaki final array: " << endl;
    for (i = 0; i<15; i++){
             cout << "0x" << hex << FinalArray[i] << ",  " ;
	}

	cout<<endl;


//firstArray
////////////////////////////////////////////////////////////////////////////////////////////

//i                 0     1    2     3      4     5     6     7    8     9      10   11
// first array    0x8d, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d
// final array    0x8d, 0x01, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d


//i=1
//j=2
//k=

	for (i = 0; i<15; i++){
		if( compare(&firstArray[i],&FinalArray[i] ) ){
      // firstArray  {0x8d, 0x01, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
		}
		else{
        // esit degilse 2 durum olusabilir
          //1) final arrayde yok
            for(j = 1; j <= 3/* 3'e kadar dondurmek yeterli olur dedim */; j++ ){
                cout << " j:" << j << endl;
                if( (compare(&firstArray[i],&FinalArray[i+j] ))){ //ayni buldum, demek ki bizim ilk arrayimizde eksik var
                    break;
                }

            }
            cout << " j:" << j << endl;

                if(j != 0) {//bulamadim, demek ki bizim Final arrayimizde eksikler var
                    for(int k = 14 ; k > i  ; k--){
                        FinalArray[k] = FinalArray[k-1];
                    }
                    FinalArray[i] = firstArray[i];
                }


          //2) final arrayde var
		}
		cout << "tester" << endl;
	}
 cout << endl << "ilk islem sonucu" << endl;

for (i = 0; i<15; i++){
             cout << "0x" << hex << FinalArray[i] << ",  " ;
	}


//secondArray
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for (i = 0; i<15; i++){
		if( compare(&secondArray[i],&FinalArray[i] ) ){
      // firstArray  {0x8d, 0x01, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
		}
		else{
        // esit degilse 2 durum olusabilir
          //1) final arrayde yok
            for(j = 1; j <= 3/* 3'e kadar dondurmek yeterli olur dedim */; j++ ){
                cout << " j:" << j << endl;
                if( (compare(&secondArray[i],&FinalArray[i+j] ))){ //ayni buldum, demek ki bizim ilk arrayimizde eksik var
                    break;
                }

            }
            cout << " j:" << j << endl;

                if(j != 0) {//bulamadim, demek ki bizim Final arrayimizde eksikler var
                    for(int k = 14 ; k > i  ; k--){
                        FinalArray[k] = FinalArray[k-1];
                    }
                    FinalArray[i] = secondArray[i];
                }


          //2) final arrayde var
		}
		cout << "tester" << endl;
	}


cout << endl << "ikinci islem sonucu" << endl;

for (i = 0; i<15; i++){
             cout << "0x" << hex << FinalArray[i] << ",  " ;
	}



//thirdArray
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for (i = 0; i<15; i++){
		if( compare(&thirdArray[i],&FinalArray[i] ) ){
      // firstArray  {0x8d, 0x01, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
		}
		else{
        // esit degilse 2 durum olusabilir
          //1) final arrayde yok
            for(j = 1; j <= 3/* 3'e kadar dondurmek yeterli olur dedim */; j++ ){
                cout << " j:" << j << endl;
                if( (compare(&thirdArray[i],&FinalArray[i+j] ))){ //ayni buldum, demek ki bizim ilk arrayimizde eksik var
                    break;
                }

            }
            cout << " j:" << j << endl;

                if(j != 0) {//bulamadim, demek ki bizim Final arrayimizde eksikler var
                    for(int k = 14 ; k > i  ; k--){
                        FinalArray[k] = FinalArray[k-1];
                    }
                    FinalArray[i] = thirdArray[i];
                }


          //2) final arrayde var
		}
		cout << "tester" << endl;
	}



cout << endl << "ucuncu islem sonucu" << endl;

for (i = 0; i<15; i++){
             cout << "0x" << hex << FinalArray[i] << ",  " ;
	}















//lastArray
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
for (i = 0; i<15; i++){
		if( compare(&lastArray[i],&FinalArray[i] ) ){
      // firstArray  {0x8d, 0x01, 0x02, 0x08, 0x20, 0x40, 0x80, 0x1b, 0x36, 0x6c, 0xd8, 0xab, 0x4d};
		}
		else{
        // esit degilse 2 durum olusabilir
          //1) final arrayde yok
            for(j = 1; j <= 3/* 3'e kadar dondurmek yeterli olur dedim */; j++ ){
                cout << " j:" << j << endl;
                if( (compare(&lastArray[i],&FinalArray[i+j] ))){ //ayni buldum, demek ki bizim ilk arrayimizde eksik var
                    break;
                }

            }
            cout << " j:" << j << endl;

                if(j != 0) {//bulamadim, demek ki bizim Final arrayimizde eksikler var
                    for(int k = 14 ; k > i  ; k--){
                        FinalArray[k] = FinalArray[k-1];
                    }
                    FinalArray[i] = lastArray[i];
                }



          //2) final arrayde var
		}
		cout << "tester" << endl;
	}




//	for (i = 0; i<15; i++){
//             cout << "0x" << hex << FinalArray[i] << ",  " ;
//	}

cout << endl << "sonuncu islem sonucu" << endl;

for (i = 0; i<15; i++){
             cout << "0x" << hex << FinalArray[i] << ",  " ;
	}




	return 0;
};
