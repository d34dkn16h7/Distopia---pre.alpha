#include "animation.h"
Animation::Animation(Renderer* _owner)
{
    owner = _owner;
    currentClip = "default";
    clip[currentClip] = Clip();
    //anim.setTexture(owner->rSource->GetTexture(owner->GetName()));
}
void Animation::AddClip(string _name,Clip _clip)
{
    clip[_name] = _clip;
}
void Animation::Update()
{
    clip[currentClip].Update();
    anim.setTextureRect(clip[currentClip].GetRect());
}
void Animation::Draw()
{
    Debug::Event("I should draw some sprites!");
    owner->DrawSprite(anim);
}
