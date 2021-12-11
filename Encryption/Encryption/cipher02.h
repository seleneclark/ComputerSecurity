/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER02_H
#define CIPHER02_H

/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher02 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Leandro Oliveira"; }
   virtual std::string getCipherName()  { return "Vigenère Cipher"; }
   virtual std::string getEncryptAuth() { return "Leandro Oliveira"; }
   virtual std::string getDecryptAuth() { return "Leandro Oliveira"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("https://pt.planetcalc.com/2468 , http://www.bosontreinamentos.com.br/seguranca/criptografia-cifra-de-vigenere/, https://treinamento24.com/library/lecture/read/6150-como-funciona-a-cifra-de-vigenere");
   }
   
   /**********************************************************
    * GET PSEUDOCODE
    * Returns the pseudocode as a string to be used by the caller.
    **********************************************************/
   virtual std::string getPseudocode()
   {
      std::string str;

      // TODO: please format your pseudocode
      // The encrypt pseudocode
      str += "Here are the pseudocode algorithms for the encrypt and decrypt methods \n";

      str =  "Encrypted = (plainText[i] + passoword[i]) modulo 26\n";

      // The decrypt pseudocode
      str += "Decypted = (plainText[i] - passoword[i] + 26) modulo 26\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * Formats and then encrypts the plain text message using
    * the Vigenère Cipher.
    **********************************************************/
   virtual std::string encrypt(const std::string& plainText,
    const std::string& password)
  {
    std::string cipherText;
    std::string formattedPlainText;

    // Formats the message so that it can be encrypted.
    for (int i = 0; i < plainText.size(); i++)
    {
        if (isalnum(plainText[i]))
        {
            formattedPlainText += toupper(plainText[i]);
        }
    }

    for (int i = 0, j = 0; i < formattedPlainText.size(); i++)
    {
      // Encrypts the letter using the Vigenère Cipher.
       char letter = (formattedPlainText[i] + password[j]) % 26;

      // Finds the correct letter to use in the password for the        encryption algorithm above.
       j = (j + 1) % password.length();

      // Converts letter to ASCII value.
       letter += 'A';

       cipherText += letter;
    }

    return cipherText;
  }
            
   /**********************************************************
    * DECRYPT
    * Decrypts the cipher text message using the Vigenère Cipher.
    **********************************************************/
   virtual std::string decrypt(const std::string& cipherText,
    const std::string& password)
  {
    std::string plainText;
     // TODO - Add your code here
    for (int i = 0, j = 0; i < cipherText.size(); i++)
    {
      //Mssage using the Vigenère Cipher
      char letter = (cipherText[i] - password[j] + 26) % 26;

    
	
      j = (j + 1) % password.length();

      //Letter to ASCII 
      letter += 'A';
      plainText += letter;
    }

    return plainText;
  }
};

#endif // CIPHER02_H
