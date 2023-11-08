#include <iostream>
#include <vector>
using namespace std;

//white 2 black 1
const string start_position =
    "         \n"  
    "         \n"  
    " rnbqkbnr\n"  
    " pppppppp\n"  
	 " ........\n"  
    " ........\n"  
    " ........\n"  
    " ........\n"  
    " PPPPPPPP\n" 
    " RNBQKBNR\n"  
    "         \n"  
    "         \n";
const int w,a,s,d=-10,-1,10,1;
const int rook_sup[4]={-10,-1,1,10};
const int bishop_sup[4]={-11,-9,9,11};
const int knight_sup[8]={w+w+a,w+w+d,s+s+a,s+s+d,a+a+w,a+a+s,d+d+w,d+d+s};

int move_gen(int side, string board){
	vector <int> r;

	//take every square
	for (int i=20; i<100;i++){

		//rook and queen moves
		if(board[i]=="r" && side==1 || board[i]=="R" && side==2 || board[i]=="q" && side==1 || board[i]=="Q" && side==2){
			 for(int j=0; j<4;j++){
				  for(int k=1; k<8;k++){
						if(islower(board[i+rook_sup[j]*k])!=islower(board[i]) || board[i+rook_sup[j]*k]=="."){
							 r.push_back(i);
							 r.push_back(i+rook_sup[j]*k);
						}
						else{
							 break;
						}
				  }
			 }
		}
		
		//bishop and queen moves
		if(board[i]=="b" && side==1 || board[i]=="B" && side==2 || board[i]=="q" && side==1 || board[i]=="Q" && side==2){
			 for(int j=0; j<4;j++){
				  for(int k=1; k<8;k++){
						if(islower(board[i+bishop_sup[j]*k])!=islower(board[i]) || board[i+bishop_sup[j]*k]=="."){
							 r.push_back(i);
							 r.push_back(i+bishop_sup[j]*k);
						}
						else{
							 break;
						}
				  }
			 }
		}

		//king moves
		if(board[i]=="k" && side==1 || board[i]=="K" && side==2){
			for(int j=0; j<4; j++){
				 if(islower(board[i+bishop_sup[j]])!=islower(board[i]) || board[i+bishop_sup[j]]=="."){
					  r.push_back(i);
					  r.push_back(i+bishop_shop[j]):
				 }
				 if(islower(board[i+rook_sup[j]])!=islower(board[i]) || board[i+rook_sup[j]]=="."){
					  r.push_back(i);
					  r.push_back(i+rook_shop[j]):
				 }
			}
		}

		//knight moves
		if(board[i]=="n" && side==1 || board[i]=="N" && side==2){
			for(int j=0; j<8; j++){
				 if(islower(board[i+knight_sup[j]])!=islower(board[i]) || board[i+knight_sup[j]]=="."){
					  r.push_back(i);
					  r.push_back(i+bishop_shop[j]):
				 }
			}
		}
		//now fucking pawns
		if(board[i]=="p" && side==1 || board[i]=="P" && side==2){
			 //for side 1
			 if(side==1){
			 	  if(board[i+s]=="."){
				  r.push_back(i);
				  r.push_back(i+s);
				  }
				  if(i<40 && i>30 && board[i+s]=="." && board[i+s+s]){
						r.push_back(i);
						r.push_back(i+s+s);
				  }
				  if(!islower(board[i+9])){
						r.push_back(i);
						r.push_back(i+9);
				  }
				  if(!islower(board[i+11])){
						r.push_back(i);
						r.push_back(i+11);
				  }
			 }
			 //for side 2
			 if(side==2){
			 	  if(board[i-s]=="."){
				  r.push_back(i);
				  r.push_back(i-s);
				  }
				  if(i<100 && i>90 && board[i-s]=="." && board[i-s-s]){
						r.push_back(i);
						r.push_back(i-s-s);
				  }
				  if(!islower(board[i-9])){
						r.push_back(i);
						r.push_back(i-9);
				  }
				  if(!islower(board[i-11])){
						r.push_back(i);
						r.push_back(i-11);
				  }
			 }

		}
		//end of pawns

	}
	//whole board scanned
	return r;
	// return format:  [45,46,45,48] (45 to 46 and 45 to 48 is playable)
}
//end of move gens



int main(){
	cout << start_position;
	return 0;
}



