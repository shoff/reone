/*
 * Copyright � 2020 Vsevolod Kremianskii
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <map>

#include <stdexcept>

#include "types.h"

using namespace std;

namespace reone {

namespace resources {

static map<ResourceType, string> g_extByType = {
    { ResourceType::Bmp, "bmp" },
    { ResourceType::Tga, "tga" },
    { ResourceType::Wav, "wav" },
    { ResourceType::PackedLayerTexture, "plt" },
    { ResourceType::Ini, "init" },
    { ResourceType::Text, "txt" },
    { ResourceType::Model, "mdl" },
    { ResourceType::ScriptSource, "nss" },
    { ResourceType::CompiledScript, "ncs" },
    { ResourceType::Area, "are" },
    { ResourceType::Tileset, "set" },
    { ResourceType::ModuleInfo, "ifo" },
    { ResourceType::Creature, "bic" },
    { ResourceType::Walkmesh, "wok" },
    { ResourceType::TwoDa, "2da" },
    { ResourceType::ExtraTextureInfo, "txi" },
    { ResourceType::GameInstance, "git" },
    { ResourceType::Bti, "bti" },
    { ResourceType::ItemBlueprint, "uti" },
    { ResourceType::Btc, "btc" },
    { ResourceType::CreatureBlueprint, "utc" },
    { ResourceType::Conversation, "dlg" },
    { ResourceType::TilePalette, "itp" },
    { ResourceType::TriggerBlueprint, "utt" },
    { ResourceType::Dds, "dds" },
    { ResourceType::SoundBlueprint, "uts" },
    { ResourceType::LetterComboProbability, "ltr" },
    { ResourceType::Gff, "gff" },
    { ResourceType::Faction, "fac" },
    { ResourceType::EncounterBlueprint, "ute" },
    { ResourceType::DoorBlueprint, "utd" },
    { ResourceType::PlaceableBlueprint, "utp" },
    { ResourceType::DefaultValues, "dft" },
    { ResourceType::GameInstanceComments, "gic" },
    { ResourceType::Gui, "gui" },
    { ResourceType::MerchantBlueprint, "utm" },
    { ResourceType::DoorWalkmesh, "dwk" },
    { ResourceType::PlaceableWalkmesh, "pwk" },
    { ResourceType::Journal, "jrl" },
    { ResourceType::WaypointBlueprint, "utw" },
    { ResourceType::SoundSet, "ssf" },
    { ResourceType::ScriptDebugger, "ndb" },
    { ResourceType::PlotManager, "ptm" },
    { ResourceType::PlotWizardBlueprint, "ptt" },
    { ResourceType::AreaLayout, "lyt" },
    { ResourceType::Vis, "vys" },
    { ResourceType::Texture, "tpc" },
    { ResourceType::Mdx, "mdx" } };

static map<string, ResourceType> g_typeByExt;

const string &getExtByResType(ResourceType type) {
    auto it = g_extByType.find(type);
    if (it != g_extByType.end()) return it->second;

    g_extByType.insert(make_pair(type, to_string(static_cast<int>(type))));

    return g_extByType[type];
}

ResourceType getResTypeByExt(const string &ext) {
    if (g_typeByExt.empty()) {
        for (auto &entry : g_extByType) {
            g_typeByExt.insert(make_pair(entry.second, entry.first));
        }
    }
    auto it = g_typeByExt.find(ext);
    if (it == g_typeByExt.end()) {
        throw runtime_error("Resource type not found by extension: " + ext);
    }

    return it->second;
}

} // namespace resources

} // namespace reone