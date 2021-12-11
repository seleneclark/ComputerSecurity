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
   * GETMATRIXKEY
   * Use password to create the matrix key
   **********************************************************/
   void getMatrixKey(const std::string & plainText, const std::string & password)
   {
	  matrixSize = (int)plainText.length();
	  key = new int[matrixSize * matrixSize];
	  int testArr[3][3] = { {6,24,1}, {13,16,10}, {20,17,15}};
	  for (int i = 0; i < matrixSize; i++)
	  {
		 for (int j = 0; j < matrixSize; j++)
		 {
			*(key + (i * matrixSize) + j) = testArr[i][j];
//			*(key + (i * matrixSize) + j) = rand() % 100;
		 }
	  }

   }

   /**********************************************************
   * MATRIXMULTIPLY
   * Multiply the key matrix against the plainText to get the cipherMatrix
   **********************************************************/
   void matrixMultiply( const std::string & plainText)
   {
	  int messageVector[matrixSize][1];
	  for (int i = 0; i < matrixSize; i++)
	  {
		 messageVector[i][0] = (int)plainText[i] - 65;;
	  }
	  for (int i = 0; i < matrixSize; i++)
	  {
		 for (int j = 0; j < 1; j++)
		 {
			cypherMatrix[i][j] = 0;
			for (int x = 0; x < 3; x++)
			{
			   cypherMatrix[i][j] += * (key + (i * matrixSize) + x) * messageVector[x][j];
			}
		 cypherMatrix[i][j] = cypherMatrix[i][j] % 26;
		 }
	  }
   }
   
   /**********************************************************
   * MATRIXTOSTRING
   * Convert the matrix to a string
   **********************************************************/
   string matrixToString()
   {
	 string text;
	 for (int i = 0; i < matrixSize; i++)
	 {
		text += 'A' + cypherMatrix[i][0];
	 }
	 return text;
   }
   
   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string encrypt(const std::string & plainText,
                               const std::string & password)
   {
	  getMatrixKey(plainText, password);
	  matrixMultiply(plainText);
	  string cypherText = matrixToString();
	  return cypherText;
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
   
   
private:
   int *key;
   int matrixSize;
   int cypherMatrix[][1];
   //   float *inv;
};

#endif // CIPHER01_H
