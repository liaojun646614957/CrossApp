//
//  CASlider.h
//  project
//
//  Created by lh on 14-4-16.
//  Copyright (c) 2014 http://9miao.com All rights reserved.
//

#ifndef __project__CASlider__
#define __project__CASlider__

#include <iostream>
#include "view/CAView.h"
#include "view/CAScale9ImageView.h"
#include "view/CARenderImage.h"

NS_CC_BEGIN

typedef enum
{
    CAProgressStyleDefault=0,
    CAProgressStyleBar
}CAProgressStyle;

class CC_DLL CAProgress :public CAView
{
public:
    
    CAProgress();
    
    virtual ~CAProgress();
    
    bool init();
    
    static CAProgress* create();
    
    virtual void onEnterTransitionDidFinish();
    
    virtual void onExitTransitionDidStart();
    
	void setProgress(float progress, bool animated = false);

	float getProgress();

public:
    
    CC_SYNTHESIZE_PASS_BY_REF(CAProgressStyle, m_pProgressStyle, ProgressStyle);
    
    CC_SYNTHESIZE_PASS_BY_REF(CAColor4B, m_progressTintColor, ProgressTintColor);
    
    CC_SYNTHESIZE_PASS_BY_REF(CAColor4B, m_progresstrackColor, ProgresstrackColor);
    
	CC_SYNTHESIZE_RETAIN(CAImage*, m_pProgressTintImage, ProgressTintImage);
    
	CC_SYNTHESIZE_RETAIN(CAImage*, m_pProgressTrackImage, ProgressTrackImage);
    
protected:

    void setContentSize(const CCSize & var);
    
	void update(float dt);
    
	void animatedBegin();

	void animatedFinish();

    CAScale9ImageView* m_pTarckImageView;
    
	CAScale9ImageView* m_pProgressImageView;

	float m_fProgress;

    CAView* m_pIndicator;
};

NS_CC_END
#endif /* defined(__project__CASlider__) */
