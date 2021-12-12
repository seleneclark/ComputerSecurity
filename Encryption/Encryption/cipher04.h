/********************************************************************
* Header:
*    Implement your cipher here. You can view 'example.h' to see the
*    completed Caesar Cipher example.
********************************************************************/
#ifndef CIPHER04_H
#define CIPHER04_H
#include <bits/stdc++.h>
using namespace std;
/********************************************************************
 * CLASS
 *******************************************************************/
class Cipher04 : public Cipher
{
public:
   virtual std::string getPseudoAuth()  { return "Landon Egbers"; }
   virtual std::string getCipherName()  { return "Rail Fence"; }
   virtual std::string getEncryptAuth() { return "Landon Egebrs"; }
   virtual std::string getDecryptAuth() { return "Landon Egbers"; }

   /***********************************************************
    * GET CIPHER CITATION
    * Returns the citation from which we learned about the cipher
    ***********************************************************/
   virtual std::string getCipherCitation()
   {
      return std::string("http://rumkin.com/tools/cipher/railfence.php by Tyler Akins.  Publish date: unknonwn");
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
      str =  "Input 1: String we are trying to encode.  Input 2: Password.  Get the number of rows in the rail fence.  Rows in the rail fence = number of characters in the password.  Matrix.  Rows = number of rails.  Columns = length of the message.  [0,0]: Put first letter of the matrix here.  Add 1 to the X coordinate for each added letter.  Add 1 to the Y coordinate until you reach the bottom of the matrix.  If you are at the bottom of the matrix, subtract 1 from the Y coordinate, until you get back to 0.  If you get back to 0, start adding to the Y coordinate again.  Repeat this pattern until you have reached the end of the X axis.  The order that these letters appear is the order in which the letters should appear to a user who wishes to decrypt the message.  Return these letters in this order.\n";

      // The decrypt pseudocode
      str += "Get the string we are trying to decode.  Get the password.  If the password is correct, [0,0]: the first letter to be read from the matrix.  Add 1 to the X coordinate for each added letter.  Add 1 to the Y coordinate until you reach the bottom of the matrix.  If you are at the bottom of the matrix, subtract 1 from the Y coordinate, until you get back to 0.  If you get back to 0, start adding to the Y coordinate again.  Repeat this pattern until you have reached the end of the X axis.  If the password is not correct, read the [0,0] coordinate first, then continue to increase the X axis without changing the Y axis.  Repeat this until you have reached the end of the X axis.  Then repeat the X axis, starting from 0 but add 1 to the Y axis.  Repeat this patter until you have reached the end of both the X and Y axis.\n";

      return str;
   }

   /**********************************************************
    * ENCRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string encrypt(const std::string & text,
                               const std::string & password)
   {
       int key = password.length();
// function to encrypt a message
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][(text.length())];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j = 0; j < text.length(); j++)
            rail[i][j] = '\n';
 
    // to find the direction
    bool dir_down = false;
    int row = 0, col = 0;
 
    for (int i=0; i < text.length(); i++)
    {
        // check the direction of flow
        // reverse the direction if we've just
        // filled the top or bottom rail
        if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        // fill the corresponding alphabet
        rail[row][col++] = text[i];
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    //now we can construct the cipher using the rail matrix
    string result;
    for (int i=0; i < key; i++)
        for (int j=0; j < text.length(); j++)
            if (rail[i][j]!='\n')
                result.push_back(rail[i][j]);
 
    return result;
}

   /**********************************************************
    * DECRYPT
    * TODO: ADD description
    **********************************************************/
   virtual std::string decrypt(const std::string& cipher,
       const std::string& password)
{
           int key = password.length();
    // create the matrix to cipher plain text
    // key = rows , length(text) = columns
    char rail[key][cipher.length()];
 
    // filling the rail matrix to distinguish filled
    // spaces from blank ones
    for (int i=0; i < key; i++)
        for (int j=0; j < cipher.length(); j++)
            rail[i][j] = '\n';
 
    // to find the direction
    bool dir_down;
 
    int row = 0, col = 0;
 
    // mark the places with '*'
    for (int i=0; i < cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
 
        // place the marker
        rail[row][col++] = '*';
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }
 
    // now we can construct the fill the rail matrix
    int index = 0;
    for (int i=0; i<key; i++)
        for (int j=0; j<cipher.length(); j++)
            if (rail[i][j] == '*' && index<cipher.length())
                rail[i][j] = cipher[index++];
 
 
    // now read the matrix in zig-zag manner to construct
    // the resultant text
    string result;
 
    row = 0, col = 0;
    for (int i=0; i< cipher.length(); i++)
    {
        // check the direction of flow
        if (row == 0)
            dir_down = true;
        if (row == key-1)
            dir_down = false;
 
        // place the marker
        if (rail[row][col] != '*')
            result.push_back(rail[row][col++]);
 
        // find the next row using direction flag
        dir_down?row++: row--;
    }
    return result;
}
};
#endif // CIPHER04_H
