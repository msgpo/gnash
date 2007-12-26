// 
//   Copyright (C) 2005, 2006, 2007 Free Software Foundation, Inc.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

#ifndef __RC_H__
#define __RC_H__

// This is generated by autoconf
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "tu_config.h"

#include <string>
#include <vector>
#include <sys/shm.h>		// for key_t

namespace gnash {
  
class DSOEXPORT RcInitFile 
{
public:

    // Return the default instance of RC file,
    static RcInitFile& getDefaultInstance();

    bool loadFiles();

    bool parseFile(const std::string& filespec);
    bool updateFile(const std::string& filespec);
    
    bool useSplashScreen() const { return _splashScreen; }
    void useSplashScreen(bool value);

    bool useActionDump() const { return _actionDump; }
    void useActionDump(bool value);

    bool useParserDump() const { return _parserDump; }
    void useParserDump(bool value);

    bool useWriteLog() const { return _writeLog; }
    void useWriteLog(bool value);

    int getTimerDelay() const { return _delay; }
    void setTimerDelay(int x) { _delay = x; }

    int getMovieLibraryLimit() const { return _movieLibraryLimit; }

    bool showASCodingErrors() const { return _verboseASCodingErrors; }
    void showASCodingErrors(bool value);

    bool showMalformedSWFErrors() const { return _verboseMalformedSWF; }
    void showMalformedSWFErrors(bool value);

    bool enableExtensions() const { return _extensionsEnabled; }

    /// Return true if user is willing to start the gui in "stop" mode
    //
    /// defaults to false.
    ///
    bool startStopped() const { return _startStopped; }

    bool insecureSSL() const { return _insecureSSL; }
    
    int verbosityLevel() const { return _verbosity; }
    void verbosityLevel(int value) { _verbosity = value; }
    
    void setDebugLog(std::string &x) { _log = x; }
    const std::string& getDebugLog() const { return _log; }
    void setDocumentRoot(std::string &x) { _wwwroot = x; }
    std::string getDocumentRoot() { return _wwwroot; }
    
    bool useDebugger() const { return _debugger; }
    void useDebugger(bool value) { _debugger = value; }

    bool useSound() const { return _sound; }
    void useSound(bool value) { _sound = value; }

    // strk: I'd drop this, and allow an -f switch to select
    //       the gnashrc file to use instead
    bool usePluginSound() const { return _pluginSound; }
    void usePluginSound(bool value) { _pluginSound = value; }

    bool useLocalDomain() const { return _localdomainOnly; }
    void useLocalDomain(bool value);
    
    bool useLocalHost() const { return _localhostOnly; }
    void useLocalHost(bool value);

    const std::vector<std::string>& getWhiteList() const { return _whitelist; }
    const std::vector<std::string>& getBlackList() const { return _blacklist; }

    const std::string& getFlashVersionString() const { return _flashVersionString; }

    const std::string& getFlashSystemOS() const { return _flashSystemOS; }

    const std::string& getFlashSystemManufacturer() const { return _flashSystemManufacturer; }

    int getRetries() const { return _retries; }
    void setRetries(int x) { _retries = x; }

    /// Return the number of seconds of inactivity before timing out streams downloads
    double getStreamsTimeout() const { return _streamsTimeout; }

    /// Set the number of seconds of inactivity before timing out streams downloads
    void setStreamsTimeout(double x) { _streamsTimeout = x; }

    typedef std::vector<std::string> PathList;

    /// Return the list of directories to be used as the 'local' sandbox
    //
    /// Local sendbox is the set of resources on the filesystem we want to
    /// give the current movie access to.
    ///
    const PathList& getLocalSandboxPath() const { return _localSandboxPath; }

    /// Add a directory to the local sandbox list
    void addLocalSandboxPath(const std::string& dir)
    {
        _localSandboxPath.push_back(dir);
    }

    /// Set the local sandbox list
    void setLocalSandboxPath(const PathList& path)
    {
        _localSandboxPath = path;
    }

    // Get the location of the sandbox for .sol files
    const std::string &getSOLSafeDir() const { return _solsandbox; }

    /// Get the URL opener command format
    //
    /// The %u label will need to be substituted by the actual url
    /// properly excaped.
    ///
    const std::string &getURLOpenerFormat() const
    {
        return _urlOpenerFormat;
    }

    // Set the location of the sandbox for .sol files
    void setSOLSafeDir(std::string &x) { _solsandbox = x; }

    bool getSOLLocalDomain() const { return _sollocaldomain; }
    void setSOLLocalDomain(bool x) { _sollocaldomain = x; }
    bool getSOLReadOnly() const { return _solreadonly; }
    void setSOLReadOnly(bool x) { _solreadonly = x; }
    bool getLocalConnection() const { return _lcdisabled; }
    void setLocalConnection(bool x) { _lcdisabled = x; }
    // Enable tracing all LocalConnection traffic
    bool getLCTrace() const { return _lctrace; }
    void setLCTrace(bool x) { _lctrace = x; }

    // 
    key_t getLCShmKey() const { return _lcshmkey; }
    void setLCShmKey(bool x) { _lcshmkey = x; }
    
    void dump();    

private:
    uint32_t  _delay;                // the timer delay
    uint32_t  _movieLibraryLimit;    // max number of movie clips to store in the library
    bool _debug;                // enable debugging of this class
    bool _debugger;             // enable the Flash movie debugger
    uint32_t  _verbosity;

    /// Command format to use to open urls
    //
    /// The %u label will need to be substituted by the url
    /// (properly escaped)
    ///
    std::string  _urlOpenerFormat;

    /// String to pass as $version in Actionscript
    std::string  _flashVersionString;

    /// String to pass as System.capabilities.os
    /// in Actionscript. If empty, leaves detection
    /// to System.cpp (default).
    std::string  _flashSystemOS;       

    /// String to pass as
    /// System.capabilities.manufacturer
    /// in Actionscript
    std::string  _flashSystemManufacturer;

    /// enable dumping actionscript classes
    bool _actionDump;

    /// enable dumping parser data
    bool _parserDump;

    /// Enable ActionScript errors verbosity
    bool _verboseASCodingErrors;

    /// Enable Malformed SWF verbosity
    bool _verboseMalformedSWF;
    
    
    /// End user Features
    bool _splashScreen;        // display a splash screen when
                                // loading a movie
    /// Security Features
    bool _localdomainOnly;     // only access network resources for
                                // the local domain
    bool _localhostOnly;       // only access network resources 
    std::vector<std::string> _whitelist; // domains we allow
    std::vector<std::string> _blacklist; // domains we don't allow
    std::string _log;           // the name of the debug log
    bool _writeLog;             // enable writing the debug log to disk
    std::string _wwwroot;       // the root path for the streaming server
    int _retries;               // the number of retries for a thread
    bool _sound;		// whether sound is enable or not
    bool _pluginSound;		// whether sound is desired for the plugin

    bool _extensionsEnabled;	// whether to scan plugin path for extensions

    bool _startStopped;		// whether to start the gui in "stop" mode

    bool _insecureSSL;		// When TRUE, does not verify SSL certificates
				// so is INSECURE.

    /// The number of seconds of inactivity triggering download timeout
    double _streamsTimeout;

    /// Local sandbox: the set of resources on the filesystem we want to
    /// give the current movie access to.
    PathList _localSandboxPath;

    // SOL Sandbox: This is the only dir .sol (Shared Object) files can be written in,
    // or read from.
    std::string _solsandbox;

    bool _solreadonly;
    bool _sollocaldomain;
    bool _lcdisabled;
    bool _lctrace;
    key_t _lcshmkey;
protected:
    
    /// Construct only by getDefaultInstance()
    RcInitFile();

    /// Never destroy (TODO: add a destroyDefaultInstance)
    ~RcInitFile();

    void expandPath(std::string& path); //path string operations

    static bool extractSetting(bool *var, const char *pattern,
                        std::string &variable, std::string &value);
    
    static uint32_t extractNumber(uint32_t *num, const char *pattern,
                        std::string &variable, std::string &value);

    static void extractDouble(double& out, const char *pattern,
                        std::string &variable, std::string &value);

    void parseList(std::vector<std::string>& list, std::string &action,
			std::string &listname, std::string &items);

};

//extern DSOEXPORT RcInitFile rcfile;

// End of gnash namespace 
}

// __RC_H__
#endif


// local Variables:
// mode: C++
// indent-tabs-mode: t
// End:
