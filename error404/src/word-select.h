#pragma once

#include <string>

using namespace std;

string wordSelect(int gameDificulty) {
    if (gameDificulty == 3) {
        string hardWords[100] = {
            "zephyr", "quixotic", "onomatopoeia", "obfuscate", "larynx", "rhythmic", "phlegm", "syzygy", "mnemonic",
            "euphemism", "chiaroscuro", "susurrus", "juxtapose", "labyrinthine", "apotheosis", "esoteric", "nefarious",
            "obsequious", "dichotomy", "echelon", "paradoxical", "quagmire", "vicissitude", "conundrum", "nebulous",
            "pernicious", "egregious", "ubiquitous", "xenophobia", "cryptic", "aesthetic", "paraphernalia", "kaleidoscope",
            "dystopian", "cataclysmic", "quandary", "hyperbole", "gargantuan", "clairvoyant", "malevolent", "euphoria",
            "incongruous", "nonchalant", "resilient", "inscrutable", "melancholy", "serendipity", "impetuous", "ephemeral",
            "ineffable", "soliloquy", "grandiloquent", "oblivion", "ascetic", "pragmatic", "hegemony", "fastidious",
            "perspicacious", "idiosyncrasy", "magnanimous", "surreptitious", "penultimate", "anachronistic", "disenfranchise",
            "intransigent", "cacophony", "apothecary", "flabbergasted", "rambunctious", "querulous", "vociferous",
            "inexorable","insidious", "mellifluous", "halcyon", "bombastic", "recalcitrant", "vitriolic", "zenith", "abyss",
            "crypt", "oracle", "nebula", "fathomless", "specter", "pandemonium", "requiem", "languish", "trepidation", "vindictive",
            "tenebrous", "diaphanous", "nocturnal", "abhorrent", "bellicose", "winsome", "calliope", "gossamer", "quasar",
            "enigmatic"
        };

        return hardWords[rand() % 100];
    }
    else if(gameDificulty == 2) {
        string mediumWords[100] = {
        "mountain","computer","elephant","festival","library","painter",
        "country","pocket","dangerous","diamond","picture","holiday","journey",
        "umbrella","whisper","capture","blanket","compass","battery","crystal",
        "lantern","harvest","gravity","kingdom","horizon","freedom","fortune",
        "mystery","orchard","rainbow","station","correct","plastic","weather",
        "flowerpot","adventure","machine","history","teacher","student","village",
        "castle","brother","sister","plastic","bridge","market","forest","galaxy",
        "fiction","pirate","captain","monster","treasure","courage","puzzle",
        "window","engineer","pioneer","magnet","bottle","painter","culture",
        "whistle","thunder","lightning","volcano","explorer","planet","mission",
        "dolphin","sunrise","sunset","harbour","blanket","trouble","science",
        "cactus","factory","orchid","desert","highway","battery","fortune",
        "journal","spiral","package","carousel","shadow","emerald","ruby",
        "sapphire","feather","goblin","dragon","lantern","companion","voyage",
        "picture"
        };

        return mediumWords[rand() % 100];
    }
    else {
        string easyWords[100] = {
        "apple","ball","cat","dog","fish","book","tree","star","blue","red",
        "green","bird","milk","shoe","rain","sun","moon","hat","cup","king",
        "queen","car","boat","plane","frog","desk","chair","door","game",
        "rock","leaf","cake","cookie","mouse","horse","sheep","goat","duck",
        "road","map","coin","flag","pen","pencil","paper","clock","bell",
        "ring","soap","bed","lamp","rose","snow","ice","fire","wind","grass",
        "cloud","sand","beach","shell","bread","jam","honey","salt","water",
        "juice","soup","tea","coffee","plate","fork","knife","spoon","pearl",
        "seed","plant","farm","city","river","lake","field","wall","house",
        "story","movie","smile","laugh","hand","foot","face","hair","nose",
        "ear","kite","rope","balloon","storm"
        };

        return easyWords[rand() % 100];
    }
}