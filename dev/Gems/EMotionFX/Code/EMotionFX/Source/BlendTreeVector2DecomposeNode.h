/*
* All or portions of this file Copyright (c) Amazon.com, Inc. or its affiliates or
* its licensors.
*
* For complete copyright and license terms please see the LICENSE at the root of this
* distribution (the "License"). All use of this software is governed by the License,
* or, if provided, by the license below or the license accompanying this file. Do not
* remove or modify any license notices. This file is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*
*/

#pragma once

// include the required headers
#include "EMotionFXConfig.h"
#include "AnimGraphNode.h"


namespace EMotionFX
{
    /**
     *
     */
    class EMFX_API BlendTreeVector2DecomposeNode
        : public AnimGraphNode
    {
    public:
        AZ_RTTI(BlendTreeVector2DecomposeNode, "{E5321E8E-9FA3-4F14-B730-8FC5D6C01B3C}", AnimGraphNode)
        AZ_CLASS_ALLOCATOR_DECL

        //
        enum
        {
            INPUTPORT_VECTOR    = 0,
            OUTPUTPORT_X        = 0,
            OUTPUTPORT_Y        = 1
        };

        enum
        {
            PORTID_INPUT_VECTOR = 0,
            PORTID_OUTPUT_X     = 0,
            PORTID_OUTPUT_Y     = 1,
        };

        BlendTreeVector2DecomposeNode();
        ~BlendTreeVector2DecomposeNode();

        bool InitAfterLoading(AnimGraph* animGraph) override;

        uint32 GetVisualColor() const override          { return MCore::RGBA(128, 255, 128); }

        const char* GetPaletteName() const override;
        AnimGraphObject::ECategory GetPaletteCategory() const override;

        static void Reflect(AZ::ReflectContext* context);

    private:
        void Update(AnimGraphInstance* animGraphInstance, float timePassedInSeconds) override;
    };
}   // namespace EMotionFX
