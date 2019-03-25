#pragma once

/*
 * DEV DONATION SETTING
 * This setting is a percentage of your hashing power that the miner donates to the developers of this app.
 * It can be 0.0 if you don't want to help the developers. The default setting of 5.0 means that
 * the miner will mine into your usual pool for 95 minutes, then switch to the developer's pool for 5.0 minutes.
 * Switching pools is instant and it only happens after a successful connection, so you don't lose any hash time.
 *
 * If you're gonna disable this please do consider a one off donation to 1XTCY5LqdBXRW6hcHtnuMU7c68mAyW6qm bitcoin address. This donation
 * mining helps us fund our servers etc.
 */

constexpr double fDevDonationLevel = 5.0 / 100.0;
