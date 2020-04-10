(function ($) {
  Drupal.behaviors.devel = {
    attach: function (context, settings) {
      hostingSiteBackupManagerRefreshList = function() {
      if (!settings.hostingSiteBackupManager.nid) {
        return null;
      }

      var hostingSiteBackupManagerCallback = function(data, responseText) {
        $("#hosting-site-backup-manager-backupstable").html(data.markup);
          setTimeout("hostingSiteBackupManagerRefreshList()", 30000);
        }

        //hostingTaskAddOverlay('#hosting-site-backup-manager-backupstable');
        $.get(Drupal.settings.basePath + 'node/' + settings.hostingSiteBackupManager.nid + '/ajax/backups', null, hostingSiteBackupManagerCallback , 'json');
      }
      if($("#hosting-site-backup-manager-backupstable")) {
        setTimeout("hostingSiteBackupManagerRefreshList()", 30000);
      }
    }
  }
})(jQuery);
