/*
 * SoundEffect.h
 * n8
 *
 * Author:          Nate Ebel
 * Date:            4/14/14
 * Organization:    n8Tech
 *
 */

#ifndef SOUNDEFFECT_H
#define SOUNDEFFECT_H

#include <iostream>
#include <string>

#include "Resource.h"

namespace n8{
    
    /** \class SoundEffect
     *  \brief SoundEffect resource that can be played
     *
     *  SoundEffect wraps Mixer.Mix_Chunk struct
     */
class SoundEffect : public Resource{
public:
    SoundEffect(std::string p_id, Mix_Chunk* p_mixChunk);
    ~SoundEffect();
    
private:
    
    Mix_Chunk* m_soundEffect; /** < The sound effect data */
    
    friend class AudioService;
};
    
}

#endif /* defined(SOUNDEFFECT_H) */
