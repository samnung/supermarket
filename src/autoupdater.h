#ifndef AUTOUPDATER_H
#define AUTOUPDATER_H

class AutoUpdater {
  public:
	explicit AutoUpdater() {}
	virtual ~AutoUpdater() {}
	virtual void checkForUpdates() = 0;
	virtual void checkForUpdatesInBackground() = 0;
};

#endif // AUTOUPDATER_H
