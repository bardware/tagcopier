// tagcopier.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

using namespace std;


int main(int argc, char* argv[])
{

    /* 1. CREATE AN OBJECT */
    AnyOption *opt = new AnyOption();

    /* 2. SET PREFERENCES  */
    //opt->noPOSIX(); /* do not check for POSIX style character options */
    //opt->setVerbose(); /* print warnings about unknown options */
    //opt->autoUsagePrint(true); /* print usage for bad options */

    /* 3. SET THE USAGE/HELP   */
    opt->addUsage("");
    opt->addUsage("Usage: ");
    opt->addUsage("");
    opt->addUsage(" -h  --help  		Prints this help ");
    opt->addUsage(" -s  --size 42 	        Image Size ");
    opt->addUsage(" -z  --zip  		Compress Image ");
    opt->addUsage(" -c   			convert Image ");
    opt->addUsage("     --name image.jpg	Image Name ");
    opt->addUsage("");

    /* 4. SET THE OPTION STRINGS/CHARACTERS */
    opt->setFlag("help", 'h');   /* a flag (takes no argument), supporting long and short form */
    opt->setOption("size", 's'); /* an option (takes an argument), supporting long and short form */

    /* 5. PROCESS THE COMMANDLINE AND RESOURCE FILE */
    opt->processCommandArgs(argc, argv);

    if (!opt->hasOptions()) { /* print usage if no options */
        opt->printUsage();
        delete opt;
        return 1;
    }

    /* 6. GET THE VALUES */
    if (opt->getFlag("help") || opt->getFlag('h'))
        opt->printUsage();
    if (opt->getValue('s') != NULL || opt->getValue("size") != NULL)
        cout << "size = " << opt->getValue('s') << endl;
    if (opt->getValue("name") != NULL)
        cout << "name = " << opt->getValue("name") << endl;
    if (opt->getValue("title") != NULL)
        cout << "title = " << opt->getValue("title") << endl;
    if (opt->getFlag('c'))
        cout << "c = flag set " << endl;
    if (opt->getFlag('z') || opt->getFlag("zip"))
        cout << "zip = flag set " << endl;
    cout << endl;

    /* 7. GET THE ACTUAL ARGUMENTS AFTER THE OPTIONS */
    for (int i = 0; i < opt->getArgc(); i++) {
        cout << "arg = " << opt->getArgv(i) << endl;
    }

    /* 8. DONE */
    delete opt;
  
    //for (int i = 1; i < argc; i++) {

    //    cout << "******************** \"" << argv[i] << "\" ********************" << endl;

    //    TagLib::FileRef f(argv[i]);

    //    if (!f.isNull() && f.tag()) {

    //        TagLib::Tag *tag = f.tag();

    //        cout << "-- TAG (basic) --" << endl;
    //        cout << "title   - \"" << tag->title() << "\"" << endl;
    //        cout << "artist  - \"" << tag->artist() << "\"" << endl;
    //        cout << "album   - \"" << tag->album() << "\"" << endl;
    //        cout << "year    - \"" << tag->year() << "\"" << endl;
    //        cout << "comment - \"" << tag->comment() << "\"" << endl;
    //        cout << "track   - \"" << tag->track() << "\"" << endl;
    //        cout << "genre   - \"" << tag->genre() << "\"" << endl;

    //        TagLib::PropertyMap tags = f.file()->properties();

    //        unsigned int longest = 0;
    //        for (TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
    //            if (i->first.size() > longest) {
    //                longest = i->first.size();
    //            }
    //        }

    //        cout << "-- TAG (properties) --" << endl;
    //        for (TagLib::PropertyMap::ConstIterator i = tags.begin(); i != tags.end(); ++i) {
    //            for (TagLib::StringList::ConstIterator j = i->second.begin(); j != i->second.end(); ++j) {
    //                cout << left << setw(longest) << i->first << " - " << '"' << *j << '"' << endl;
    //            }
    //        }

    //    }

    //    if (!f.isNull() && f.audioProperties()) {

    //        TagLib::AudioProperties *properties = f.audioProperties();

    //        int seconds = properties->length() % 60;
    //        int minutes = (properties->length() - seconds) / 60;

    //        cout << "-- AUDIO --" << endl;
    //        cout << "bitrate     - " << properties->bitrate() << endl;
    //        cout << "sample rate - " << properties->sampleRate() << endl;
    //        cout << "channels    - " << properties->channels() << endl;
    //        cout << "length      - " << minutes << ":" << setfill('0') << setw(2) << seconds << endl;
    //    }
    //}

    cout << "Press enter to continue ...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}
