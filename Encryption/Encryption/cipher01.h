/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#include <stdio.h>
using namespace std;

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher01 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Selene Clark"; }
	  virtual std::string getCipherName()  { return "Hill Cypher"; }
	  virtual std::string getEncryptAuth() { return "Selene Clark"; }
	  virtual std::string getDecryptAuth() { return "Selene Clark"; }
   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
	  std::string s;
	  s += "Hill, Lester S. “Cryptography in an Algebraic Alphabet.”\n";
	  s += "    The American Mathematical Monthly, vol. 36, no. 6,\n";
	  s += "    Mathematical Association of America, 1929, pp. 306–12,\n";
	  s += "    https://doi.org/10.2307/2298294.";
	  return std::string(s);
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
	  std::string str;
	  // The encrypt pseudocode
	  str =  "encrypt(plainText, password)\n";
	  str += "   key <- getMatrixKey(password)\n";
	  str += "   cipherText <- matrixMultiply(key, plainText)\n";
	  str += "   RETURN cipherText\n\n";

	  // The decrypt pseudocode
	  str += "decrypt(cipherText, password)\n";
	  str += "   key <- getMatrixKey(password)\n";
	  str += "   decryptKey <- getInverseMatrix(key)\n";
	  str += "   plainText  <- matrixMultiply(decryptKey, cipherText)\n";
	  str += "   RETURN plainText\n\n";

	  return str;
   }

   /**********************************************************
   * MATRIXMULTIPLY
   * Multiply the key matrix against the plainText to get the cipherMatrix
   **********************************************************/
   void matrixMultiply(int key[3][3],  const std::string & plainText, int cipherMatrix[3][1] )
   {
	  int messageVector[3][1] = { 2, 0, 19};
	  for (int i = 0; i < 3; i++)
	  {
		 for (int j = 0; j < 1; j++)
		 {
		 cipherMatrix[i][j] = 0;

			for (int x = 0; x < 3; x++)
			{
			   cipherMatrix[i][j] +=
			   key[i][x] * messageVector[x][j];
			}
		 cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
		 }
	  }
   }
   
   /**********************************************************
   * MATRIXTOSTRING
   * Convert the matrix to a string
   **********************************************************/
   std::string matrixToString(int matrix[][1] )
   {
	 std::string text;
	 int size = 3;
	 for (int i = 0; i < size; i++)
	 {
		text += 'A' + matrix[i][0];
	 }
	 return text;
   }
   
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & plainText, 
                               const std::string & password)
   {
	  int key[3][3] = { {6,24,1}, {13,16,10}, {20,17,15}};
	  int cipherMatrix[3][1];

	  matrixMultiply(key, plainText, cipherMatrix);
	  std::string cipherText = matrixToString(cipherMatrix);
	  //      std::string cipherText = plainText;
	  return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
};

#endif // CIPHER01_H
