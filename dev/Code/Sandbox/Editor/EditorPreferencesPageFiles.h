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

#include "Include/IPreferencesPage.h"
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/RTTI/RTTI.h>
#include <AzCore/Math/Vector3.h>


class CEditorPreferencesPage_Files
    : public IPreferencesPage
{
public:
    AZ_RTTI(CEditorPreferencesPage_Files, "{5574AAD2-7619-4C61-A095-CBE70BDB3BF3}", IPreferencesPage)

    static void Reflect(AZ::SerializeContext& serialize);

    CEditorPreferencesPage_Files();
    virtual ~CEditorPreferencesPage_Files() = default;

    virtual const char* GetCategory() override { return "General Settings"; }
    virtual const char* GetTitle() override { return "Files"; }
    virtual void OnApply() override;
    virtual void OnCancel() override {}
    virtual bool OnQueryCancel() override { return true; }

private:
    void InitializeSettings();

    struct Files
    {
        AZ_TYPE_INFO(Files, "{9952889C-2A03-4A8B-8ECB-27A2BCC9D7F6}")

        bool m_autoNumberSlices;
        bool m_backupOnSave;
        int m_backupOnSaveMaxCount;
        AZStd::string m_standardTempDirectory;
        bool m_autoSaveTagPoints;
    };

    struct ExternalEditors
    {
        AZ_TYPE_INFO(ExternalEditors, "{6D04DAA8-C0DF-4AFE-B263-9B95619B2527}")

        AZStd::string m_scripts;
        AZStd::string m_shaders;
        AZStd::string m_BSpaces;
        AZStd::string m_textures;
        AZStd::string m_animations;
    };

    struct AutoBackup
    {
        AZ_TYPE_INFO(AutoBackup, "{C4EC2E11-EBE4-4DAE-B1E2-EB4C8731ECEE}")

        bool m_enabled;
        int m_timeInterval;
        int m_maxCount;
        int m_remindTime;
    };


    Files m_files;
    ExternalEditors m_editors;
    AutoBackup m_autoBackup;
};

