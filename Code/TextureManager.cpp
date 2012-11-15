#include "textureManager.h"
TextureManager::TextureManager(string source = "null")
{
    if(source != "null")
        load(source);
}
void TextureManager::load(string source)
{
    ifstream file(source.c_str());
    string fName,tag;
    int animCount;
    while(file >> fName >> tag >> animCount)
    {
        sf::Texture tempImg;
        if(tempImg.loadFromFile(fName))
        {
            AddTexture(tempImg,tag,animCount);
            cout << fName << " : has loaded with this tag : " << tag << endl;
        }
        else
            cout << fName << " : CAN'T LOAD: " << tag << endl;
    }
}
void TextureManager::AddTexture(sf::Texture& img,string key,int animCount)
{
    aList[key] = animCount;
    iList[key] = img;
}
sf::Texture& TextureManager::GetTexture(string key)
{
    return iList[key];
}
sf::Texture TextureManager::GetTextureVar(string key)
{
    return iList[key];
}
int TextureManager::GetAnimCount(string key)
{
    return aList[key];
}
