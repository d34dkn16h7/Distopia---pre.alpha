#include "textureManager.h"
TextureManager::TextureManager(string source)
{
    imgCount = 0;
    if(source != "null")
        load(source);
}
void TextureManager::load(string source)
{
    ifstream file(source.c_str());
    string fName,tag,clipFile;
    while(file >> fName >> tag >> clipFile)
    {
        Debug::Error(clipFile);
        sf::Texture tempImg;
        if(tempImg.loadFromFile(fName))
        {
            AddTexture(tempImg,tag,clipFile);
            //cout << "New file -"<<fName << " : " << clipFile << endl;
        }
    }
}
void TextureManager::AddTexture(sf::Texture& img,string key,string clipFile)
{
    imgCount++;
    iList[key] = img;
    clip_files[key] = clipFile;
}
sf::Texture& TextureManager::GetTexture(string key)
{
    return iList[key];
}
sf::Texture TextureManager::GetTextureVar(string key)
{
    return iList[key];
}
string TextureManager::GetClipSource(string key)
{
    return clip_files[key];
}
