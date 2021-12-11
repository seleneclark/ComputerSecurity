/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER01_H
#define CIPHER01_H
#define MATRIXSIZE 2
#define CHARACTER_SIZE 61
#include <stdio.h>
#include <math.h>
#include <string.h>
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
   * INDEX
   * gets the index for a 2D array to be used with a pointer
   **********************************************************/
   int index(int i, int j)
   {
	  return i * MATRIXSIZE + j;
   }

   void copyKey(int k[2][2])
   {
	  for (int i = 0; i < MATRIXSIZE; i++)
	  {
		 for (int j = 0; j < MATRIXSIZE; j++)
		 {
			key[i][j] = k[i][j];
		 }
	  }
   }
   
   /**********************************************************
   * GETMATRIXKEY
   * Use password to create the matrix key
   **********************************************************/
   void getMatrixKey(const std::string & plainText, const std::string & password)
   {
	  int pass = 0;
	  for (int i = 0; i < password.length(); i++)
	  {
		 pass += (int)password[i];
	  }
	  pass = pass % 3;
	  int key0[2][2] = {{2,3}, {5,7}};
	  int key1[2][2] = {{4,3}, {5,4}};
	  int key2[2][2] = {{4,3}, {3,2}};
	  switch (pass)
	  {
		 case 0:
			copyKey(key0);
			break;
		 case 1:
			copyKey(key1);
			break;
		 default:
			copyKey(key2);
	  }
   }

   /**********************************************************
   * MATRIXMULTIPLY
   * Multiply the key matrix against the plainText to get the cipherMatrix
   **********************************************************/
   void matrixMultiply( const std::string & plainText)
   {
	  int messageVector[MATRIXSIZE];
	  for (int i = 0; i < MATRIXSIZE; i++)
	  {
		 messageVector[i] = (int)plainText[i] - 65;
	  }
	  for (int i = 0; i < MATRIXSIZE; i++)
	  {
		 matrix[i] = 0;

		 for (int j = 0; j < MATRIXSIZE; j++)
		 {
			   matrix[i] += key[i][j] * messageVector[j];
		 }
		 matrix[i] = matrix[i] % CHARACTER_SIZE;
	  }
   }
   
   /**********************************************************
   * INVERSEMATRIXMULTIPLY
   * Multiply the iinverse matrix against the plainText to get the cipherMatrix
   **********************************************************/
//   void inverseMatrixMultiply( const std::string & plainText)
//   {
//	  *(inverseKey) = 0.158730159;
//	  *(inverseKey + 1) = -0.619047619;
//	  *(inverseKey + 2) = 0.507936508;
//	  *(inverseKey + 3) = 0.011337868;
//	  *(inverseKey + 4) = 0.158730159;
//	  *(inverseKey + 5) = -0.106575964;
//	  *(inverseKey + 6) = -0.224489796;
//	  *(inverseKey + 7) = 0.857142857;
//	  *(inverseKey + 8) = -0.489795918;
//
//
////	  displayDouble(inverseKey);
//	  int messageVector[MATRIXSIZE][1];
//	  for (int i = 0; i < MATRIXSIZE; i++)
//	  {
//		 messageVector[i][0] = (int)plainText[i] - 65;;
//	  }
//
//	  for (int i = 0; i < MATRIXSIZE; i++)
//	  {
//		 for (int j = 0; j < MATRIXSIZE; j++)
//		 {
//			double num =remainder(* (inverseKey + index(i,j)), CHARACTER_SIZE);
//			* (inverseKey + index(i,j)) = num ;
//		 }
//	  }
////	  displayDouble(inverseKey);
//	  for (int i = 0; i < MATRIXSIZE; i++)
//	  {
//		 for (int j = 0; j < 1; j++)
//		 {
//			for (int x = 0; x < 3; x++)
//			{
//			   double temp = (* (inverseKey + index(i,x))) * messageVector[x][j];
//			   matrix[i][j] += (int)temp;
//			}
//
//		 }
//	  }
//   }
   
   
   /**********************************************************
   * MATRIXTOSTRING
   * Convert the matrix to a string
   **********************************************************/
   string matrixToString(int matrix[])
   {
	 string text;
	 for (int i = 0; i < MATRIXSIZE; i++)
	 {
		if (matrix[i] < 0)
		{
		   matrix[i] = matrix[i]+ CHARACTER_SIZE;
		}
		text += 'A' + matrix[i];
	 }
	 return text;
   }
   
   /**********************************************************
   * GETCOFACTOR
   * Get the cofactor of the matrix
   **********************************************************/
//   void getCofactor(int * A, int * temp, int p, int q, int n)
//   {
//	  int N = 3;
//	  int i = 0, j = 0;
//
//	  // Looping for each element of the matrix
//	  for (int row = 0; row < n; row++)
//	  {
//		 for (int col = 0; col < n; col++)
//		 {
//			 //  Copying into temporary matrix only those element
//			 //  which are not in given row and column
//			 if (row != p && col != q)
//			 {
//				* (temp + index(i,j)) = * (A + index(i,j));
//
//				 // Row is filled, so increase row index and
//				 // reset col index
//				 if (j == n - 1)
//				 {
//					 j = 0;
//					 i++;
//				 }
//			 }
//		 }
//	  }
//   }

   /**********************************************************
   * DETERMINANT
   * Get the determinant of the matrix
   **********************************************************/
//   int determinant(int * A, int n)
//   {
//	  int D = 0; // Initialize result
////
////	  //  Base case : if matrix contains single element
////	  if (n == 1)
////		return * A;
////
////	  int *temp= new int[MATRIXSIZE * MATRIXSIZE]; // To store cofactors
////	  int sign = 1;  // To store sign multiplier
////
////	  // Iterate for each element of first row
////	  for (int f = 0; f < n; f++)
////	  {
////		// Getting Cofactor of key[0][f]
////		getCofactor(A, temp, 0, f, n);
////		D += sign * (* (A + index(0,f) )) * determinant(temp, n - 1);
////
////		// terms are to be added with alternate sign
////		sign = -sign;
////	  }
////
//	  return D;
//
//   }

   /**********************************************************
   * ADJOINT
   * Get the inverse matrix
   **********************************************************/
//   void adjoint(int * adj)
//   {
//	  int N = MATRIXSIZE;
//	  if (N == 1)
//	  {
//		 *adj = 1;
//		 return;
//	  }
//
//	   // temp is used to store cofactors of key
//	  int sign = 1;
//	  int * temp= new int[MATRIXSIZE * MATRIXSIZE];
//	  for (int i=0; i<N; i++)
//	  {
//		for (int j=0; j<N; j++)
//		{
//			// Get cofactor of A[i][j]
//			getCofactor(key, temp, i, j, N);
//
//			// sign of adj[j][i] positive if sum of row
//			// and column indexes is even.
//			sign = ((i+j)%2==0)? 1: -1;
//
//			// Interchanging rows and columns to get the
//			// transpose of the cofactor matrix
//			*(adj + index(i,j)) = (sign)*(determinant(temp, N-1));
//		}
//	  }
//   }
   /**********************************************************
   * INVERSE
   * Get the inverse matrix
   **********************************************************/
   bool getInverse(const std::string & password)
   {
	  int pass = 0;
	  for (int i = 0; i < password.length(); i++)
	  {
		 pass += (int)password[i];
	  }
	  pass = pass % 3;
	  int key0[2][2] = {{-7,3}, {5,-2}};
	  int key1[2][2] = {{4,-3}, {-5,4}};
	  int key2[2][2] = {{-2,3}, {3,-4}};
	  switch (pass)
	  {
		 case 0:
			copyKey(key0);
			break;
		 case 1:
			copyKey(key1);
			break;
		 default:
			copyKey(key2);
	  }
	  return true;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual string encrypt(const std::string & plainText,
                               const std::string & password)
   {
	  getMatrixKey(plainText, password);
	  string cipherText = "";
	  for (int i = 0; i < plainText.length(); i = i + 2)
	  {
		 matrixMultiply(plainText.substr(i, 2));
		 cipherText += matrixToString(matrix);
	  }
	  return cipherText;
   }

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string & cipherText, 
                               const std::string & password)
   {
	  string plainText= "";
	  getInverse(password);
	  for (int i = 0; i < cipherText.length(); i = i + 2)
	  {
		 matrixMultiply(cipherText.substr(i, 2));
		 plainText += matrixToString(matrix);
	  }
//	  matrixMultiply(cipherText);
//	  string plainText = matrixToString(matrix);
//      std::string plainText = cipherText;
      // TODO - Add your code here
      return plainText;
   }
   
   
private:
   int key[2][2];
//   double * inverseKey;
   int matrix[];
   
};

#endif // CIPHER01_H
