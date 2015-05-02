#include <string>

using namespace std;

class Protash
{
private:
	int N;
	int count1;
/* metrhths gia to plh8os twn leksewn se mia protash */
	string* s;							
/* metablhth typou deikth se symboloseira gia thn akolou8ia leksewn se 
mia protash */
	static const string dictionary[10];			
/* leksiko me tis apodektes sumboloseires */
	static const string dictionary_False[5];	/* leksiko me 
tis lan8asmenes sumboloseires-den proerxontai apo thn ekfwnhsh */
public:
	Protash(int);								
/* constructor ths klasshs Protash */
	~Protash( );								
/* destructor ths klasshs Protash */

	void spell_correct(string*);				
/* synarthsh gia th dior8wsh twn leksewn ths protashs-pairnei ws orisma 
to s */
	int word_count( );							
/* synarthsh gia th metrhsh tou plh8ous twn leksewn mias 
protashs-epistrefei ton count1 */
	string* read_phrase( );						
/* synarthsh gia na diabazontai oi lekseis ths protashs-epistrefei to s 
*/
};



class Paragraphos
{
private:
	int count2;									
/* metrhths gia to plh8os twn leksewn se mia paragrapho */
public:
	Protash* par[10];							
/* deikths se pinaka antikeimenwn typou class Protash */

	Paragraphos(int);							
/* constructor ths klasshs Paragraphos */
	~Paragraphos( );							
/* destructor ths klasshs Paragraphos */

	void spell_correct(Protash*[ ]);			
/* synarthsh gia th dior8wsh twn leksewn ths protashs-pairnei ws orisma 
deikth se pinaka antikeimenwn typou class Protash */
	int word_count( );							
/* synarthsh gia th metrhsh tou plh8ous twn leksewn mias 
protashs-epistrefei ton count2 */

};


class Ekthesh
{
private:
	int MaxWords, MinWords;
	string title;								
/* metablhth typou symboloseiras gia ton titlo ths ektheshs */
	int count3;									
/* metrhths gia to plh8os twn leksewn se mia ekthesh */
public:
	Paragraphos* ek[7];							
/* deikths se pinaka typou class Paragraphos */

	Ekthesh(string, int);						
/* constructor ths klasshs Ekthesh */
	~Ekthesh( );								
/* destructor ths klasshs Ekthsesh */

	void spell_correct(Paragraphos*[ ]);		/*synarthsh gia 
th dior8wsh twn leksewn ths protashs-pairnei ws orisma deikth se pinaka 
antikeimenwn typou class Paragraphos*/
	void evaluate_length(int, int);				
/* synarthsh gia ton elegxo ths ektashs ths ektheshs */
};

