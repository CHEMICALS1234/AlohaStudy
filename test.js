function ExamDownload(
  ExPapr_No,
  Exfl_Group,
  SiteID,
  ExPapr_Group,
  IsAutoExamDown,
  Subj_Code,
  Grade,
  exPapr_Coretype,
) {
  _event_freedown = 'N';

  if (typeof ExPapr_Group == 'undefined') ExPapr_Group = '';
  if (typeof IsAutoExamDown == 'undefined') IsAutoExamDown = false;
  if (typeof Subj_Code == 'undefined') Subj_Code = '';
  if (typeof Grade == 'undefined') Grade = '';
  if (typeof exPapr_Coretype == 'undefined') exPapr_Coretype = '';

  var IsChk_History = true;
  var chk_result;

  // 일부 학교별 예상족보는 중복다운로드 체크를 하지 않는다.
  //if (ExPapr_Group == 'V' && (Subj_Code == 'LS' || Subj_Code == 'HI' || Subj_Code == 'SC' || (SiteID == 'H' && Subj_Code == 'MT')))
  //{
  //    IsChk_History = false;
  //}

  _ExPapr_No = ExPapr_No;
  _Exfl_Group = Exfl_Group;
  _SiteID = SiteID;

  //	console.log(1, _event_freedown);

  // 로그인 및 권한 체크

  if (_event_freedown == 'Y') {
    // 이벤트 무료 다운로드 (2020.09.14, 정효태)
  } else {
    if (
      !Download_Check(
        ExPapr_No,
        Exfl_Group,
        ExPapr_Group,
        Subj_Code,
        Grade,
        exPapr_Coretype,
      )
    ) {
      return;
    }
  }

  // 학교별예상족보는 중등 과학,사회,역사/고등 수학,사회,국사,과학의 경우 최초 클릭시 무조건 AutoExam을 호출한다.
  // 이후 범위 선택 페이지에서 다운로드 클릭 시에는 IsAutoExamDown값을 true로 보내 Download가 이루어진다.
  if (ExPapr_Group == 'V' && IsAutoExamDown == false) {
    ExamDownload_AutoExam();
  } else {
    //console.log(2, IsChk_History, ExPapr_No, Exfl_Group, SiteID);

    // 고등 > 학평변형 다운로드 안내창 구분을 위한 분기처리.
    if (SiteID == 'H' && ExPapr_Group == 'D' && exPapr_Coretype == 'E') {
      if (IsChk_History) {
        // 다운로드 기록 체크
        /*
				결과값 : 0 다운로드 기록이 없음...
				결과값 : 1 재다운로드지만 30일 기간 지남..
				결과값 : 2 재다운로드지만 30일 기간 안지남..
				결과값 : 3 취소
				*/
        chk_result = DownloadHistory_Check(ExPapr_No, Exfl_Group, SiteID);

        switch (chk_result) {
          case 2:
            TransformExamDownload_Confirm(ExPapr_No, Exfl_Group, SiteID, 1); //재 다운로드
            return;
            break;
          case 3:
            return;
            break;
        }
      }

      TransformExamDownload_Confirm(ExPapr_No, Exfl_Group, SiteID, 2); //일반 다운로드
    } else {
      if (IsChk_History) {
        // 다운로드 기록 체크
        /*
				결과값 : 0 다운로드 기록이 없음...
				결과값 : 1 재다운로드지만 30일 기간 지남..
				결과값 : 2 재다운로드지만 30일 기간 안지남..
				결과값 : 3 취소
				*/

        //chk_result = DownloadHistory_Check(ExPapr_No, Exfl_Group, SiteID);
        //console.log(3, IsChk_History, ExPapr_No, Exfl_Group, SiteID, chk_result);

        if (ExPapr_Group == 'V') {
          chk_result = 0;
        } else {
          chk_result = DownloadHistory_Check(ExPapr_No, Exfl_Group, SiteID);
        }

        switch (chk_result) {
          case 2:
            ExamDownload_Confirm(ExPapr_No, Exfl_Group, SiteID, 1); //재 다운로드
            return;
            break;
          case 3:
            return;
            break;
        }
      }

      ExamDownload_Confirm(ExPapr_No, Exfl_Group, SiteID, 2); //일반 다운로드
    }
  }
}

function ExamDownload_Confirm(
  ExPapr_No,
  Exfl_Group,
  SiteID,
  flag,
  Part_Id_Set,
) {
  //console.log(_event_freedown);
  var _url =
    '/Common/ExamDownload/DownloadConfirm.asp?ExPapr_No=' +
    ExPapr_No +
    '&Exfl_Group=' +
    Exfl_Group +
    '&flag=' +
    flag +
    '&SiteID=' +
    SiteID +
    '&evt_free=' +
    _event_freedown +
    '&Part_Id_Set=' +
    Part_Id_Set;

  if (jQuery(window).height() != jQuery(window.parent).height()) {
    // 중고등 메인 및 상세보기 추천컨텐츠는 iframe으로 되어있다.
    var _parent = jQuery(window.parent);
    var iHeight = (_parent.height() - 470) / 2;
    var iWidth = (_parent.width() - 450) / 2;
    var maskHeight = jQuery(window.parent.document).height();
    var maskWidth = _parent.width();

    jQuery('#levelTest', parent.document)
      .css({ top: iHeight, left: iWidth })
      .show();
    jQuery('#gameplayer', parent.document).append(
      '<iframe src=' +
        _url +
        " frameBorder='0' scrolling='no' width='450' height='480'>",
    );
    jQuery('#mask', parent.document)
      .css({ width: maskWidth, height: maskHeight })
      .fadeTo('slow', 0.2);
  } else {
    var iHeight = (jQuery(window).height() - 470) / 2;
    var iWidth = (jQuery(window).width() - 450) / 2;
    var maskHeight = jQuery(document).height();
    var maskWidth = jQuery(window).width();

    jQuery('#levelTest').css({ top: iHeight, left: iWidth }).show();
    jQuery('#gameplayer').append(
      '<iframe src=' +
        _url +
        " frameBorder='0' scrolling='no' width='450' height='480'>",
    );
    jQuery('#mask')
      .css({ width: maskWidth, height: maskHeight })
      .fadeTo('slow', 0.2);
  }
}

javascript: ExamDownload('10887150', '3', 'H', 'A', '', 'MT', '1', '');
